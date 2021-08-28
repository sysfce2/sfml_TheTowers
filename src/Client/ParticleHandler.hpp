#pragma once

#include "ParticleQuad.hpp"
#include "Shader.hpp"
#include "Particle.hpp"
#include "Camera.hpp"
#include "TextureArray.hpp"
#include <vector>

class ParticleHandler {
public:


	void init(TextureArray* _array);
	void update(float deltaTime);
	void render(Camera& camera);
	void destroy();

	void placeParticlesAroundBlock(int x, int y, int z, uint8_t _blockID);


private:

	std::vector<math::mat4> m_matrices;
	std::vector<Particle> m_particles;
	ParticleQuad m_quad;
	TextureArray* m_textureArray = nullptr;
	Shader m_shader;

};

