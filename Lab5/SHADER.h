#pragma once
#ifndef __SHADER_H__ 
#define __SHADER_H__ 
#include <glew.h> 
/* Dinh nghia kieu du lieu vec3 tuong duong voi GLSL */
typedef struct {
	union {
		struct { float x, y, z; };      // truy xuat thong qua xyz 
		struct { float r, g, b; };      // truy xuat thong qua rgb 
		float data[3];                  // truy xuat thong qua chi so 
	};
} vec3;
/*Kieu doi tuong shader can thao tac+ */
typedef enum glslShader { VERTEX_SHADER, FRAGMENT_SHADER } GLSL_SHADER;
/* Kieu doi tuong shader GLSL */
typedef struct glslProgram {
	GLuint program;
	GLboolean linked;
} GLSL_PROGRAM;
/* Cac ham xu ly tren doi tuong chuong trinh khac shader */
GLSL_PROGRAM * glslCreate();
void      glslDestroy(GLSL_PROGRAM * p);
GLboolean glslCompileFile(GLSL_PROGRAM * p, GLSL_SHADER type,
	const GLchar * fileName);
GLboolean glslCompileString(GLSL_PROGRAM * p, GLSL_SHADER type,
	const GLchar * source);
GLboolean glslLink(GLSL_PROGRAM * p);
GLboolean glslActivate(GLSL_PROGRAM * p);
void      glslDeactivate(GLSL_PROGRAM * p);
/* cac ham thao tac tren bien uniform */
GLint     glslGetUniform(GLSL_PROGRAM * p, const GLchar * name);
GLboolean glslSetUniform1f(GLSL_PROGRAM * p, const GLchar * name, GLfloat v);
GLboolean glslSetUniform3f(GLSL_PROGRAM * p, const GLchar * name,
	GLfloat x, GLfloat y, GLfloat z);
GLboolean glslSetUniform3fv(GLSL_PROGRAM * p, const GLchar * name, const vec3 v);

#endif 