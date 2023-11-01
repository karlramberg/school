package com.drawing;

import com.jogamp.opengl.GL2;

public class GCloud implements GShape {

	private GCircle leftThird;
	private GCircle middleThird;
	private GCircle rightThird;
	
	private float position;
	private final float SPEED = -0.2f;
	private final float MAX_POSITION = 200.0f;
	
	GCloud(float x, float y, float r) {
		this.position = 0.0f;
		
		// Create the three parts of the cloud
		// Offset the left and right thirds using the radius
		leftThird = new GCircle(x - r, y, r * 0.8f, 32);
		middleThird = new GCircle(x, y, r, 32);
		rightThird = new GCircle(x + r, y, r * 0.6f, 32);
		
		// Set the color for each to white
		float color[] = {0.941f, 0.973f, 1.0f, 0.941f, 0.973f, 1.0f};
		leftThird.setColor(color);
		middleThird.setColor(color);
		rightThird.setColor(color);
	}
	
	@Override
	public void render(GL2 gl) {
		gl.glPushMatrix();
		
		position += SPEED;
		if (position < 0.0f) {
			position = MAX_POSITION;
		}
		gl.glTranslatef(position, 0.0f, 0.0f);
		
		leftThird.render(gl);
		middleThird.render(gl);
		rightThird.render(gl);
		
		gl.glPopMatrix();
	}
}
