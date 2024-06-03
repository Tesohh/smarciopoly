#include "tile.hpp"
#include "assets.hpp"
#include "raylib.h"
#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

game::Tile::Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone) {
    this->spritePath = spritePath;
    this->sprite = LoadImage(this->spritePath.c_str());
    this->pos.x = x;
    this->pos.y = y;
    this->rotation = rotation;
    this->tileType = tileType;
    this->cost = cost;
    this->zone = zone;

    updateTexture();
}

void game::Tile::debugPrint() {
    std::printf("TYPE: %d, ROT: %d, X: %f, Y: %f\n", this->tileType, this->rotation, this->pos.x, this->pos.y);
}

void game::Tile::updateTexture() { 
    // PERF: image and texture should be unlaoded
    this->editedImage = ImageCopy(this->sprite);

    if (this->tileType == TileType::PROPERTY) {
        std::string str = "$" + std::to_string(this->cost);
        int textWidth = MeasureTextEx(game::fonts.uiFont, str.c_str(), 110, 0).x;
        int textX = this->editedImage.width / 2 - textWidth / 2;


        // ImageDrawText(&this->editedImage, str.c_str(), textX, 670, 100, BLACK);

        ImageDrawTextEx(&this->editedImage,
                        game::fonts.uiFont,
                        str.c_str(),
                        Vector2{(float) textX, 650},
                        110,
                        0,
                        BLACK);
    }

    this->texture = LoadTextureFromImage(this->editedImage);
    SetTextureFilter(this->texture, TEXTURE_FILTER_BILINEAR);
}

void game::Tile::draw() {
    DrawTextureEx(this->texture, this->pos, this->rotation, 1.0f, WHITE);
};

std::vector<game::Tile> game::getTiles() {
    std::vector<game::Tile> tiles = {
        Tile("resources/tiles/start.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::START, 0, ""),
        Tile("resources/tiles/baraccopoli.png", (TILE_WIDTH*7)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/ecomostro.png", (TILE_WIDTH*6)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/viadeimulini.png", (TILE_WIDTH*5)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/casanova.png", (TILE_WIDTH*4)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/k21.png", (TILE_WIDTH*3)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chickenhut.png", (TILE_WIDTH*2)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/kebz.png", (TILE_WIDTH*1)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/prison.png", 0-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PRISON, 0, ""),
        Tile("resources/tiles/probability.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*7)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/acquarena.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*6)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/acquarena.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*5)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/bolzanosud.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*4)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/max.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*3)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/life.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*2)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/baila.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*1)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/awards.png", 0-BORDER_OVERHANG, 0-BORDER_OVERHANG, 0, TileType::AWARDS, 0, ""),
        Tile("resources/tiles/talvera.png", (TILE_WIDTH*1)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/yogurteria.png", (TILE_WIDTH*2)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/stationpark.png", (TILE_WIDTH*3)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/brixtown.png", (TILE_WIDTH*4)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chance.png", (TILE_WIDTH*5)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/twenty.png", (TILE_WIDTH*6)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/noi.png", (TILE_WIDTH*7)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/police.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0-BORDER_OVERHANG, 0, TileType::POLICE, 0, ""),
        Tile("resources/tiles/baita.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*1)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/bronzolo.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*2)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/probability.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*3)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/fortezza.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*4)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/mino.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*5)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chance.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*6)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/rikilento.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*7)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 100, ""),
    };
    
    return tiles;
}
