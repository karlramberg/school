package com.drawing;

import com.jogamp.opengl.GL2;

public class GWagon implements GShape {
	
	private GQuad chassis;
	private GCircle frontWheelOuter;
	private GCircle backWheelOuter;
	private GCircle frontWheelInner;
	private GCircle backWheelInner;
	
	GWagon(float x, float y) {
		// Chassis
		float chassisVertices[] = { x, y + 15f,           // top left
									x + 20f, y,           // bottom right
									0.502f, 0.0f, 0.0f,   // main color
									0.502f, 0.0f, 0.0f }; // outline color
		chassis = new GQuad(chassisVertices);
		
		// Outer Wheels
		frontWheelOuter = new GCircle(x + 16f, y, 5f);
		backWheelOuter = new GCircle(x + 4f, y, 5f);
		float wheelOuterColor[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		frontWheelOuter.setColor(wheelOuterColor);
		backWheelOuter.setColor(wheelOuterColor);
		
		// Inner Wheels
		frontWheelInner = new GCircle(x + 16f, y, 3f);
		backWheelInner = new GCircle(x + 4f, y, 3f);
		float wheelInnerColor[] = { 0.275f, 0.510f, 0.706f, 0.275f, 0.510f, 0.706f };
		frontWheelInner.setColor(wheelInnerColor);
		backWheelInner.setColor(wheelInnerColor);
	}
	
	@Override
	public void render(GL2 gl) {
		chassis.render(gl);
		frontWheelOuter.render(gl);
		backWheelOuter.render(gl);
		frontWheelInner.render(gl);
		backWheelInner.render(gl);
	}

}
