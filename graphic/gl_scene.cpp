#include "gl_scene.h"

goofe::graphic::GLScene::GLScene(const PackedScene& scene)
{
	impl_->memManager.build();

	indices_count = scene.indices.size();
	auto vertexData = impl_->memManager.calcVertexData(indices_count, scene.vertices.size());
	indices_offset = vertexData.indices_offset;
	buf_id = impl_->memManager.buildVertexBuffer(scene.indices, scene.vertices, vertexData);
	id = impl_->memManager.buildVertexArray(buf_id);
}

goofe::graphic::GLScene::~GLScene()
{
	impl_->memManager.delVertexData(id, buf_id);
}
