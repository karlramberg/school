package com.drawing;

import com.jogamp.opengl.GL2;

public class GTree implements GShape {

	private GEllipse leaves;
	private GQuad trunk;
	private GCircle fruit1;
	private GCircle fruit2;
	private GCircle fruit3;
	
	private float scaleFactor;
	private boolean growing;
	private float SCALE_SPEED = 0.001f;
	private float MAX_SCALE = 1.025f;
	private float MIN_SCALE = 0.975f;
	
	GTree(float x, float y) {
		this.scaleFactor = MIN_SCALE;
		this.growing = true;
		
		// Trunk
		float trunkVertices[] = { x, y + 40f,               // top left
								  x + 3f, y,                // bottom right
								  0.545f, 0.271f, 0.075f,   // main color
								  0.545f, 0.271f, 0.075f }; // outline color
		trunk = new GQuad(trunkVertices);
		
		// Leaves
		leaves = new GEllipse(x + 1.5f, y + 50f, 10f, 15f);
		
		// Fruit
		float fruitColor[] = { 0.863f, 0.078f, 0.235f, 0.863f, 0.078f, 0.078f }; 
		fruit1 = new GCircle(x - 2f, y + 45f, 2f, 32);
		fruit2 = new GCircle(x + 6f, y + 50f, 2f, 32);
		fruit3 = new GCircle(x + 1f, y + 60f, 2f, 32);
		fruit1.setColor(fruitColor);
		fruit2.setColor(fruitColor);
		fruit3.setColor(fruitColor);
	}
	
	@Override
	public void render(GL2 gl) {
		trunk.render(gl); // trunk doesnt move
		
		gl.glPushMatrix();
		
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
		
		gl.glScalef(scaleFactor, scaleFactor, 1.0f);
		leaves.render(gl);
		fruit1.render(gl);
		fruit2.render(gl);
		fruit3.render(gl);
		
		gl.glPopMatrix();
	}
}
