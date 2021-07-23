#pragma once

#include "../World/Chunk.hpp"
#include "../Utils/Camera.hpp"
#include "../Utils/ChunkShader.hpp"
#include "../../NetworkManager.hpp"
#include "../Utils/TextureArray.hpp"
#include "../../Config.hpp"
#include "../../BlockTextureHandler.hpp"
#include <cstdint>

class NetworkManager;

class World {
public:

	void init(NetworkManager& _manager, BlockTextureHandler* _textureHandler, Config& _c);
	void render(Camera& _camera);
	uint8_t getBlock(int _x, int _y, int _z);
	void setBlock(int _x, int _y, int _z, uint8_t _block);
	void destroy();

private:

	// Utility functions
	void generateMesh(Chunk* chunk);
	GLuint packData(uint8_t x, uint8_t y, uint8_t z, uint8_t lightLevel, uint8_t textureCoordinateIndex, uint16_t textureArrayIndex);
	void addBlock(Chunk* _c, int _x, int _y, int _z, uint8_t _blockType);
	bool isBlockInLocalWorld(int _x, int _y, int _z);

	// Mesh generation functions
	void addTopFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	void addBottomFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	void addRightFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	void addLeftFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	void addFrontFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	void addBackFace(Chunk* _c, uint8_t _x, uint8_t _y, uint8_t _z, uint16_t _textureLayer);
	Chunk* getChunk(int x, int y, int z);

	//We keep vertices so we dont have to reallocate memory every time we want to generate a chunk
	std::vector<GLuint> m_vertices;

	BlockTextureHandler* m_textureHandler = nullptr;
	Chunk* m_chunks = nullptr;
	ChunkShader m_shader;
	uint8_t* m_data = nullptr;
	Config m_config;

};
