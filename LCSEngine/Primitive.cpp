#include "Application.h"
#include "Primitive.h"
#include "ModuleSceneMain.h"
#include "ModuleCamera.h"
#include "AssetTexture.h"
#include "MathGeoLib/src/MathGeoLib.h"
#include "Shader.h"

Primitive::Primitive()
{
	renderMode = VBO;
}

Primitive::~Primitive() {}

void Primitive::draw()
{
	switch (renderMode)
	{
	case DIRECTMODE:
		drawDirectMode();
		break;

	case VBO:
		drawVBO();
		break;

	case VERTEXARRAY:
		drawVertexArray();
		break;
	}
}

void Primitive::changeRenderMode(bool left)
{
	switch (renderMode)
	{
	case DIRECTMODE:
		(left == true ? renderMode = VERTEXARRAY : renderMode = VBO);
		glClearColor(0.f, 0.f, 0.f, 1.f);
		break;

	case VBO:
		(left == true ? renderMode = DIRECTMODE : renderMode = VERTEXARRAY);
		glClearColor(0.f, 0.f, 0.f, 1.f);
		break;

	case VERTEXARRAY:
		(left == true ? renderMode = VBO : renderMode = DIRECTMODE);
		glClearColor(0.f, 0.f, 0.f, 1.f);
		break;
	}
}

void Primitive::initializeValues()
{
	idVertVBO = idColVBO = idVertVA = idIndVA = idColVA = 0;
}

bool Primitive::cleanUp()
{
	return true;
}

void Primitive::drawDirectMode() {}

void Primitive::drawVBO()
{
	//TODO: If more textures, on each primitive, indicate a GLuint for the texture applied to it
	/*if (App->sceneMain->actual != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, App->sceneMain->actual->ID);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	float4x4 id = float4x4::identity;

	GLuint program = App->sceneMain->shader->programs[App->sceneMain->shader->defaultShaders[DEFAULTSHADER]];

	GLint modelLoc = glGetUniformLocation(program, "model_matrix");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &id[0][0]);

	GLint viewLoc = glGetUniformLocation(program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, App->camera->getViewMatrix());

	GLint projectLoc = glGetUniformLocation(program, "projection");
	glUniformMatrix4fv(projectLoc, 1, GL_FALSE, App->camera->getProjectMatrix());

	glBindBuffer(GL_ARRAY_BUFFER, idVertVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);*/
	
	/*glVertexPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, idColVBO);
	glColorPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, idTexCoordVBO);
	glTexCoordPointer(2, GL_FLOAT, 0, NULL);*/

	/*glDrawArrays(GL_TRIANGLES, 0, verticesVBO.size());

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindTexture(GL_TEXTURE_2D, 0);*/
}

void Primitive::drawVertexArray()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, idVertVA);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, idColVA);
	glColorPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idIndVA);

	glDrawElements(GL_TRIANGLES, indicesVA.size(), GL_UNSIGNED_INT, NULL);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}