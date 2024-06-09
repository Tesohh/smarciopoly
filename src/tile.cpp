#include "tile.hpp"
#include "assets.hpp"
#include "hover.hpp"
#include "raylib.h"
#include "raymath.h"
#include "smarciomath.hpp"
#include "state.hpp"
#include <cstddef>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

game::Tile::Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone, std::string name) {
    this->spritePath = spritePath;
    this->sprite = LoadImage(this->spritePath.c_str());
    this->pos.x = x;
    this->pos.y = y;
    this->rotation = rotation;
    this->tileType = tileType;
    this->cost = cost;
    this->zone = zone;
    this->name = name;

    switch (this->tileType) {
    case START: case PRISON: case AWARDS: case POLICE:
        this->rect = Rectangle {this->pos.x, this->pos.y, TILE_WIDTH*2, TILE_HEIGHT};
        break;
    case PROPERTY: case CHANCE: case PROBABILITY:
        this->rect = Rectangle {this->pos.x, this->pos.y, TILE_WIDTH, TILE_HEIGHT};
        break;
    }
    this->rect = RotateRectangle(this->rect, this->rotation);

    this->updateTexture();
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

    if (IsHovered(this->rect)) {
        if (!game::state.isTileHoverLocked) game::state.hoveredTile = this;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            if (game::state.hoveredTile == this) game::state.isTileHoverLocked = !game::state.isTileHoverLocked;
            else {
                game::state.hoveredTile = this;
                game::state.isTileHoverLocked = true;
            }
        }
    }
};

Vector2 game::Tile::getCenter() {
    Vector2 addendum = Vector2 {this->rect.width/2, this->rect.height/2};
    if (this->rotation == 90 || this->rotation == 180)  addendum = Vector2Negate(addendum);
    // if (this->rect.width > this->rect.height) addendum = Vector2Negate(addendum);
    return Vector2Add(this->pos, addendum);
}

std::vector<game::Tile> game::getTiles() {
    std::vector<game::Tile> tiles = {
        Tile("resources/tiles/start.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::START, 0, "", ""),
        Tile("resources/tiles/baraccopoli.png", (TILE_WIDTH*7)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "smarcio", "Baraccopoli"),
        Tile("resources/tiles/ecomostro.png", (TILE_WIDTH*6)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "smarcio", "Ecomostro"),
        Tile("resources/tiles/viadeimulini.png", (TILE_WIDTH*5)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "smarcio", "Via dei Mulini 16"),
        Tile("resources/tiles/casanova.png", (TILE_WIDTH*4)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "", "Stazione di Casanova"),
        Tile("resources/tiles/k21.png", (TILE_WIDTH*3)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "restaurants", "K21"),
        Tile("resources/tiles/chickenhut.png", (TILE_WIDTH*2)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "restaurants", "Chicken Hut"),
        Tile("resources/tiles/kebz.png", (TILE_WIDTH*1)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PROPERTY, 0, "restaurants", "KeBZ"),

        Tile("resources/tiles/prison.png", 0-BORDER_OVERHANG, (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0, TileType::PRISON, 0, "", ""),
        Tile("resources/tiles/probability.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*7)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROBABILITY, 0, "", ""),
        Tile("resources/tiles/acquarena.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*6)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "brixen", "Acquarena"),
        Tile("resources/tiles/acquarena.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*5)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "brixen", "Acquarena"),
        Tile("resources/tiles/bolzanosud.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*4)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "", "Stazione di Bolzano Sud"),
        Tile("resources/tiles/max.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*3)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "clubs", "Max"),
        Tile("resources/tiles/life.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*2)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "clubs", "Life"),
        Tile("resources/tiles/baila.png", TILE_HEIGHT+BORDER_OVERHANG, (TILE_WIDTH*1)+(TILE_WIDTH)-BORDER_OVERHANG, 90, TileType::PROPERTY, 0, "clubs", "Baila"),

        Tile("resources/tiles/awards.png", 0-BORDER_OVERHANG, 0-BORDER_OVERHANG, 0, TileType::AWARDS, 0, "", ""),
        Tile("resources/tiles/talvera.png", (TILE_WIDTH*1)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "bolzanocity", "Talvera"),
        Tile("resources/tiles/yogurteria.png", (TILE_WIDTH*2)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "bolzanocity", "La Yogurteria"),
        Tile("resources/tiles/stationpark.png", (TILE_WIDTH*3)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "bolzanocity", "Parco Stazione"),
        Tile("resources/tiles/brixtown.png", (TILE_WIDTH*4)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "", "Stazione di Brixtown"),
        Tile("resources/tiles/chance.png", (TILE_WIDTH*5)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::CHANCE, 0, "", ""),
        Tile("resources/tiles/twenty.png", (TILE_WIDTH*6)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "industry", "Twenty"),
        Tile("resources/tiles/noi.png", (TILE_WIDTH*7)+(TILE_WIDTH*2)+BORDER_OVERHANG, TILE_HEIGHT+BORDER_OVERHANG, 180, TileType::PROPERTY, 0, "industry", "Noi techpark"),

        Tile("resources/tiles/police.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, 0-BORDER_OVERHANG, 0, TileType::POLICE, 0, "", ""),
        Tile("resources/tiles/baita.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*1)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, "outskirts", "La baita"),
        Tile("resources/tiles/bronzolo.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*2)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, "outskirts", "Bronzolo"),
        Tile("resources/tiles/probability.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*3)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROBABILITY, 0, "", ""),
        Tile("resources/tiles/fortezza.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*4)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, "", "Stazione di Fortezza"),
        Tile("resources/tiles/mino.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*5)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 0, "luxury", "Da Mino"),
        Tile("resources/tiles/chance.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*6)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::CHANCE, 0, "", ""),
        Tile("resources/tiles/rikilento.png", (TILE_WIDTH*8)+(TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH*7)+(TILE_WIDTH*2)+BORDER_OVERHANG, 270, TileType::PROPERTY, 100, "luxury", "Pagoda Rikilento"),
    };
    
    return tiles;
}

std::unordered_map<std::string, Color> _colorsPerZone = {
    {"smarcio", GetColor(0x2D9CDBFF)},
    {"restaurants", GetColor(0xFF2424FF)},
    {"brixen", GetColor(0x1F6008FF)},
    {"clubs", GetColor(0xE82ED5FF)},
    {"bolzanocity", GetColor(0xFFE500FF)},
    {"industry", GetColor(0xFA7601FF)},
    {"outskirts", GetColor(0xAEE70CFF)},
    {"luxury", GetColor(0x703BA1FF)},
};

Color game::getColorFromZone(std::string zone) {
    Color color;
    try {
        color = _colorsPerZone.at(zone);
    } catch (std::out_of_range) {
        color = WHITE;
    }
    return color;
}
