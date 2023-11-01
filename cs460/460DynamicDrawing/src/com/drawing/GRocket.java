package com.drawing;

import com.jogamp.opengl.GL2;

public class GRocket implements GShape {

	private GEllipse body;
	private GTriangle leftFin;
	private GTriangle rightFin;
	private GCircle window;

	private float position;
	private final float SPEED = 0.3f;
	private final float MAX_POSITION = 130f;
	
	GRocket(float x, float y) {
		this.position = 0.0f;
	
		body = new GEllipse(x + 2, y + 5, 2f, 5f);
		
		float leftFinVertices[] = { x - 1, y,
									 x + 1, y,
									 x + 1, y + 3}; 
		leftFin = new GTriangle(leftFinVertices);
		
		float rightFinVertices[] = { x + 3, y,
									 x + 5, y,
									 x + 3, y + 3}; 
		rightFin = new GTriangle(rightFinVertices);
		
		
		float windowColor[] = { 0.878f, 1.0f, 1.0f, 0.878f, 1.0f, 1.0f};
		window = new GCircle(x + 2, y + 6f, 1f, 32);
		window.setColor(windowColor);
	}
	
	@Override
	public void render(GL2 gl) {
		gl.glPushMatrix();
		
		position += SPEED;
		if(position > MAX_POSITION) {
			position = 0.0f;
		}
		
		gl.glTranslated(0.0f, position, 0.0f);
		body.render(gl);
		leftFin.render(gl);
		rightFin.render(gl);
		window.render(gl);
		
		gl.glPopMatrix();
	}

}
