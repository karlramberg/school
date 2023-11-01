package com.drawing;

import com.jogamp.opengl.GL2;

public class GHome implements GShape {

	private GQuad walls;
	private GQuad window;
	private GTriangle roof;
	
	GHome(float x, float y) {
		// Walls
		float wallVertices[] = { x, y,				       // top right
								 x + 20f, y - 20f,         // bottom right
								 0.282f, 0.239f, 0.545f,   // main color
								 0.282f, 0.239f, 0.545f }; // outline color 
		this.walls = new GQuad(wallVertices);
		
		// Window
		float windowVertices[] = { x + 4f, y - 6f,       // top left
								   x + 16f, y - 16f,     // bottom right
								   0.878f, 1.0f, 1.0f,   // main color
								   0.878f, 1.0f, 1.0f }; // outline color
		this.window = new GQuad(windowVertices);
		
		// Roof
		float roofVertices[] = { x -2f , y - 2f,      // bottom left
								  x + 22f, y - 2f,    // bottom right
								  x + 10f, y + 20f }; // top center
		this.roof = new GTriangle(roofVertices);
	}
	
	@Override
	public void render(GL2 gl) {
		walls.render(gl);
		window.render(gl);
		roof.render(gl);
	}
}
