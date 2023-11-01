package com.drawing;

import com.jogamp.opengl.GL2;

public class GCloud implements GShape {

	private GCircle leftThird;
	private GCircle middleThird;
	private GCircle rightThird;
	
	GCloud(float x, float y, float r) {
		// Create the three parts of the cloud
		// Offset the left and right thirds using the radius
		leftThird = new GCircle(x - r, y, r * 0.8f);
		middleThird = new GCircle(x, y, r);
		rightThird = new GCircle(x + r, y, r * 0.6f);
		
		// Set the color for each to white
		float color[] = {0.941f, 0.973f, 1.0f, 0.941f, 0.973f, 1.0f};
		leftThird.setColor(color);
		middleThird.setColor(color);
		rightThird.setColor(color);
	}
	
	@Override
	public void render(GL2 gl) {
		leftThird.render(gl);
		middleThird.render(gl);
		rightThird.render(gl);
	}
}
