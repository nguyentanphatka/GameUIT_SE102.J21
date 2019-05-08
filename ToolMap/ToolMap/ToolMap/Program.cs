using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace CreateTileMap
{
    class Program
    {
        static readonly string ImagePath = Path.GetFullPath("lv1.png");
        static readonly string TextPath = Path.GetFullPath("matrix.txt");
        static readonly string TilesPath = Path.GetFullPath("tiles.png");
        static readonly string TilesPath_New = Path.GetFullPath("tiles_New.png");
        static int numOfTitleSet = 0;
        // Kiểm tra 2 Bitmap có giống nhau (dùng cho HashSet và so sánh)
        class TileComparer : IEqualityComparer<Bitmap>
        {
            public bool Equals(Bitmap bmp1, Bitmap bmp2)
            {
                ImageConverter converter = new ImageConverter();

                var bmpBytes1 = new byte[1];
                var bmpBytes2 = new byte[1];

                bmpBytes1 = (byte[])converter.ConvertTo(bmp1, bmpBytes1.GetType());
                bmpBytes2 = (byte[])converter.ConvertTo(bmp2, bmpBytes2.GetType());

                SHA256Managed sha = new SHA256Managed();
                byte[] bmpHash1 = sha.ComputeHash(bmpBytes1);
                byte[] bmpHash2 = sha.ComputeHash(bmpBytes2);
                return bmpHash1.SequenceEqual(bmpHash2);
            }

            public int GetHashCode(Bitmap bmp)
            {
                return bmp.ToString().ToLower().GetHashCode();
            }
        }

        // Tạo Ma trận gồm các Tile
        static List<List<Bitmap>> CreateMapTile(string fileName)
        {
            var result = new List<List<Bitmap>>();
            Bitmap MapTiles = new Bitmap(fileName);

            var cols = MapTiles.Width >> 4;
            var rows = MapTiles.Height >> 4;

            for (var i = 0; i < rows; ++i)
            {
                var RowTiles = new List<Bitmap>();
                for (var j = 0; j < cols; ++j)
                {
                    var rect = new Rectangle(j << 4, i << 4, 16, 16);
                    var tile = MapTiles.Clone(rect, MapTiles.PixelFormat);
                    RowTiles.Add(tile);
                }
                result.Add(RowTiles);
            }
            return result;
        }

        // Tạo Set các Tile
        static HashSet<Bitmap> CreateSetTile(List<List<Bitmap>> MapTiles)
        {
            var Tiles = MapTiles.SelectMany(x => x).ToList();
            return new HashSet<Bitmap>(Tiles, new TileComparer());
        }

        // Tạo ma trận file text các Tile 16 được đánh số theo SetTiles nhận vào 1 list<list<bitmap>> là list cac bitmap của map 
        static List<List<int>> CreateMatrixTile()
        {
            var MatrixTiles = new List<List<int>>();
            var TileComparer = new TileComparer();

            //sử dụng mapfile tạo ra mảng các tile
            var MapTiles = CreateMapTile(ImagePath);
            var SetTiles = CreateSetTile(MapTiles).ToList();


            // tao ra file tile set
            var Tiles = CreateSetTile(MapTiles);
            var TilesBitmap = CreateTilesBitmap(Tiles);
            TilesBitmap.Save(TilesPath);

            ////check 2nd tileset
            var MapTiles_new = CreateMapTile(TilesPath);

            var Tiles_new = CreateSetTile(MapTiles_new);
            var TilesBitmap_new = CreateTilesBitmap(Tiles_new);
            TilesBitmap_new.Save(TilesPath_New);

            //get matrix tileSet like tilemap
            var TilesetTiles = CreateMapTile(TilesPath);
            var SetTilesSet = CreateSetTile(TilesetTiles).ToList();


            foreach (var RowTiles in MapTiles)
            {
                var Row = new List<int>();
                foreach (var Tile in RowTiles)
                {
                    foreach (var TypeTile in SetTiles)
                    {
                        if (TileComparer.Equals(TypeTile, Tile))
                        {
                            Row.Add(SetTiles.IndexOf(TypeTile) + 1);
                            break;
                        }
                    }
                }
                MatrixTiles.Add(Row);
            }

            using (var sw = new StreamWriter(TextPath))
            {
                foreach (var RowTiles in MatrixTiles)
                {
                    sw.Write(string.Join(",", RowTiles));
                    sw.WriteLine(",");
                }


            }
            return MatrixTiles;

        }

        // Tạo Tiles Bitmap bằng cách thêm các Bitmap từ SetTiless
        static Bitmap CreateTilesBitmap(HashSet<Bitmap> SetTiles)
        {
            //var bmp = new Bitmap((SetTiles.Count << 4) >> 2, 16 << 2);
            var bmp = new Bitmap((SetTiles.Count << 4), 16);
            using (Graphics g = Graphics.FromImage(bmp))
            {
                for (int i = 0; i < SetTiles.Count; ++i)
                {
                    g.DrawImage(SetTiles.ElementAt(i), i << 4, 0);
                    numOfTitleSet += 1;
                }
                //for (int x = 0; x <= 5; ++x)
                //{
                //    for (int i = (SetTiles.Count / 5) * x; i < (SetTiles.Count / 5) * (x + 1); ++i)
                //    {
                //        if (i >= SetTiles.Count)
                //        {
                //            return bmp;
                //        }
                //        g.DrawImage(SetTiles.ElementAt(i), (i - (SetTiles.Count / 5) * x) * 16, x * 16);
                //        numOfTitleSet += 1;
                //    }
                //}
            }
            return bmp;
        }

        // Thực thi
        static void Main(string[] args)
        {
            Console.WriteLine("Loading...");
            CreateMatrixTile();
            Console.WriteLine("So luong Tile Map : {0}", numOfTitleSet);
            Console.WriteLine("Success");
            Console.ReadKey();
        }
    }
}