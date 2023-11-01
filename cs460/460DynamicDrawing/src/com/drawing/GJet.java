package com.drawing;

import com.jogamp.opengl.GL2;

public class GJet implements GShape {
	
	private GCircle fire;
	private GTriangle body;
	private GCircle cockpit;
	
	private float position;
	
	private final float SPEED = 3.0f;
	private final float MAX_POSITION = 800.0f;
	
	GJet(float x, float y) {
		position = 0.0f;
		
		float fireColor[] = { 0.88f, 0.34f, 0.13f, 0.88f, 0.34f, 0.13f};
		fire = new GCircle(x - 0.5f, y + 2.5f, 1f, 32);
		fire.setColor(fireColor);
		
		float bodyVertices[] = { x, y,
								 x + 8f, y + 2.5f,
								 x, y + 5f };
		body = new GTriangle(bodyVertices);
		
		float windowColor[] = { 0.878f, 1.0f, 1.0f, 0.878f, 1.0f, 1.0f};
		cockpit = new GCircle(x + 3f, y + 2.5f, 1f, 32);
		cockpit.setColor(windowColor);
	}
	
	@Override
	public void render(GL2 gl) {
		gl.glPushMatrix();
	
		position += SPEED;
		if (position > MAX_POSITION) {
			position = 0.0f;
		}
		
		gl.glTranslatef(position, 0.0f, 0.0f);
		
		fire.render(gl);
		body.render(gl);
		cockpit.render(gl);
		
		gl.glPopMatrix();
	}
}
