package com.drawing;

import com.jogamp.opengl.GL2;

public class GFlag implements GShape {

	private GQuad pole;
	private GTriangle flag;

	private float scaleFactor;
	private boolean growing;
	private float SCALE_SPEED = 0.0005f;
	private float MAX_SCALE = 1.005f;
	private float MIN_SCALE = 0.995f;
	
	GFlag(float x, float y) {
		this.scaleFactor = MIN_SCALE;
		this.growing = true;
		
		// Flag pole
		float poleVertices[] = { x, y + 40f,
							   x + 1f, y,
							   0.0f, 0.0f, 0.0f,
							   0.0f, 0.0f, 0.0f };
		pole = new GQuad(poleVertices);
		
		// Flag
		float flagVertices[] = { x , y + 35f,
								 x , y + 40f,
								 x - 8f, y + 37.5f};
		flag = new GTriangle(flagVertices);
	
	}
	
	@Override
	public void render(GL2 gl) {
		pole.render(gl);
		
		
		if (growing) {
			if(scaleFactor < MAX_SCALE) {
				scaleFactor += SCALE_SPEED;
			} else {
				scaleFactor -= SCALE_SPEED;
				growing = false;
			}
		} else {
			if (scaleFactor > MIN_SCALE) {
				scaleFactor -= SCALE_SPEED;
			} else {
				scaleFactor += SCALE_SPEED; 
				growing = true;
			}
		}
		
		gl.glPushMatrix();
		gl.glScalef(scaleFactor, scaleFactor, 1.0f);
		flag.render(gl);
		gl.glPopMatrix();
	}
}
