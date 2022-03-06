#include "gl_scene.h"

goofe::graphic::GLScene::GLScene(const PackedScene& scene)
{
	impl_->inputManager.build();

	indices_count = scene.indices.size();
	auto vertexData = impl_->inputManager.calcVertexData(indices_count, scene.vertices.size());
	indices_offset = vertexData.indices_offset;
	impl_->buf_id = impl_->inputManager.buildVertexBuffer(scene.indices, scene.vertices, vertexData);
	id = impl_->inputManager.buildVertexArray(impl_->buf_id);
}

goofe::graphic::GLScene::~GLScene()
{
	impl_->inputManager.delVertexData(id, impl_->buf_id);
}
