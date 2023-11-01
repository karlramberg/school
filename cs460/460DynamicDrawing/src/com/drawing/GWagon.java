package com.drawing;

import com.jogamp.opengl.GL2;

public class GWagon implements GShape {
	
	private GQuad chassis;
	private GCircle frontWheelOuter;
	private GCircle backWheelOuter;
	private GCircle frontWheelInner;
	private GCircle backWheelInner;
	
	private float position;
	private float wheelTheta;
	
	private final float SPEED = 0.5f;
	private final float WHEEL_SPEED = -2.0f;
	private final float POSITION_MAX = 200.0f;
	
	GWagon(float x, float y) {
		this.position = 0.0f;
		this.wheelTheta = 0.0f;
		// Chassis
		float chassisVertices[] = { x, y + 15f,           // top left
									x + 20f, y,           // bottom right
									0.502f, 0.0f, 0.0f,   // main color
									0.502f, 0.0f, 0.0f }; // outline color
		chassis = new GQuad(chassisVertices);
		
		// Outer Wheels
		frontWheelOuter = new GCircle(x + 16f, y, 5f, 32);
		backWheelOuter = new GCircle(x + 4f, y, 5f, 32);
		float wheelOuterColor[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		frontWheelOuter.setColor(wheelOuterColor);
		backWheelOuter.setColor(wheelOuterColor);
		
		// Inner Wheels
		frontWheelInner = new GCircle(x + 16f, y, 3f, 12);
		backWheelInner = new GCircle(x + 4f, y, 3f, 12);
		float wheelInnerColor[] = { 0.275f, 0.510f, 0.706f, 0.3f, 0.3f, 0.3f };
		frontWheelInner.setColor(wheelInnerColor);
		backWheelInner.setColor(wheelInnerColor);
	}
	
	@Override
	public void render(GL2 gl) {
		gl.glPushMatrix();
		
		position += SPEED;
		if (position > POSITION_MAX) {
			position = 0.0f; 
		}
		gl.glTranslatef(position, 0.0f, 0.0f);
		
		chassis.render(gl);
		frontWheelOuter.render(gl);
		backWheelOuter.render(gl);
		
		wheelTheta += WHEEL_SPEED;
		if (wheelTheta > 360.0f) {
			wheelTheta = 0.0f;
		}
		
		gl.glPushMatrix();
		gl.glTranslatef(-41f, 14f, 0f);
		gl.glRotatef(wheelTheta, 0.0f, 0.0f, 1.0f);
		gl.glTranslatef(41f, -14f, 0f);
		frontWheelInner.render(gl);
		gl.glPopMatrix();
	
		gl.glPushMatrix();
		gl.glTranslatef(-53f, 14f, 0f);
		gl.glRotatef(wheelTheta, 0.0f, 0.0f, 1.0f);
		gl.glTranslatef(53f, -14f, 0f);
		backWheelInner.render(gl);
		gl.glPopMatrix();
		gl.glPopMatrix();
	}

}
