#include <raylib.h>
#include<vector>
#include <fstream>
#include <sstream>
std::vector<std::vector<int>> loadcsv(const std::string& path)
{
        std::vector<std::vector<int>> map;
        std::ifstream file(path);
        std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            if (!cell.empty())
                row.push_back(std::stoi(cell));
        }
        if (!row.empty())
            map.push_back(row);
    }
    return map;
}

void drawlevel(std::vector<std::vector<int>> map,int tileSize,Texture2D tileset)
{
    int tilesetCols=tileset.width/tileSize;
    for (int row = 0; row < map.size(); row++) {
			for (int col = 0; col < map[row].size(); col++) {
				int tileID = map[row][col] ;
				if (tileID < 0) continue; // empty tile in Tiled exports as -1
			
				// where to cut from in the PNG
				Rectangle src = {
					(float)((tileID % tilesetCols) * tileSize),
					(float)((tileID / tilesetCols) * tileSize),
					(float)tileSize,
					(float)tileSize
				};
			
				// where to draw on screen
				Vector2 dest = {
					(float)(col * tileSize),
					(float)(row * tileSize)
				};
			
				DrawTextureRec(tileset, src, dest, WHITE);
			}
		}
}