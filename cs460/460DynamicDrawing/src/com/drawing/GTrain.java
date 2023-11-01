package com.drawing;

import com.jogamp.opengl.GL2;

public class GTrain implements GShape {
	
	private GQuad chassis;
	private GQuad exhaust;
	private GQuad coupler;
	private GQuad cabin;
	private GQuad cabinRoof;
	private GQuad front;
	private GCircle frontWheelOuter;
	private GCircle backWheelOuter;
	private GCircle frontWheelInner;
	private GCircle backWheelInner;
	
	private float position;
	private float wheelTheta;

	private final float SPEED = 0.5f;
	private final float WHEEL_SPEED = -2.0f;
	private final float POSITION_MAX = 200.0f;

	GTrain(float x, float y) {
		this.position = 0.0f;
		this.wheelTheta = 0.0f;
		
		// Chassis
		float chassisVertices[] = { x, y + 15f,            // top left
									 x + 30f, y,           // bottom right
									 0.502f, 0.0f, 0.0f,   // main color
									 0.502f, 0.0f, 0.0f }; // outline color
		chassis = new GQuad(chassisVertices);
		
		// Exhaust
		float exhaustVertices[] = { x + 22.5f, y + 20f, // top left
								  x + 25.5f, y + 14f,   // bottom right
								  0.502f, 0.0f, 0.0f,   // main color
								  0.502f, 0.0f, 0.0f }; // outline color
		exhaust = new GQuad(exhaustVertices);
		
		// Coupler
		float couplerVertices[] = { x - 5f, y + 5f,       // top left
									x, y + 2f,            // bottom right
									0.502f, 0.0f, 0.0f,   // main color
									0.502f, 0.0f, 0.0f }; // outline color
		coupler = new GQuad(couplerVertices);
		
		// Cabin
		float cabinVertices[] = { x, y + 25f,           // top left
				                  x + 15f, y + 15.5f,   // bottom right
			                 	  0.878f, 1.0f, 1.0f,   // main color
	                  			  0.878f, 1.0f, 1.0f }; // outline color
		cabin = new GQuad(cabinVertices);
		
		// Cabin Roof
		float cabinRoofVertices[] = { x, y + 28f,           // top left
									  x + 15f, y + 25f,     // bottom right
									  0.502f, 0.0f, 0.0f,   // main color
									  0.502f, 0.0f, 0.0f }; // outline color
		cabinRoof = new GQuad(cabinRoofVertices);
		
		// Front
		float frontVertices[] = { x + 30.5f, y + 12f, // top left
								  x + 32f, y + 3f,    // bottom right
								  0.4f, 0.4f, 0.4f,   // main color
								  0.4f, 0.4f, 0.4f }; // outline color
		front = new GQuad(frontVertices);
		
		// Outer Wheels
		frontWheelOuter = new GCircle(x + 24f, y, 5f, 32);
		backWheelOuter = new GCircle(x + 8f, y + 2f, 7f, 32);
		float wheelOuterColor[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1024 };
		frontWheelOuter.setColor(wheelOuterColor);
		backWheelOuter.setColor(wheelOuterColor);
		
		// Inner Wheels
		frontWheelInner = new GCircle(x + 24f, y, 3f, 12);
		backWheelInner = new GCircle(x + 8f, y + 2f, 5f, 12);
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
		exhaust.render(gl);
		coupler.render(gl);
		cabin.render(gl);
		cabinRoof.render(gl);
		front.render(gl);
		frontWheelOuter.render(gl);
		backWheelOuter.render(gl);

		wheelTheta += WHEEL_SPEED;
		if (wheelTheta > 360.0f) {
			wheelTheta = 0.0f;
		}
		
		gl.glPushMatrix();
		gl.glTranslatef(-8f, 14f, 0f);
		gl.glRotatef(wheelTheta, 0.0f, 0.0f, 1.0f);
		gl.glTranslatef(8f, -14f, 0f);
		frontWheelInner.render(gl);
		gl.glPopMatrix();
	
		gl.glPushMatrix();
		gl.glTranslatef(-24f, 16f, 0f);
		gl.glRotatef(wheelTheta, 0.0f, 0.0f, 1.0f);
		gl.glTranslatef(24f, -16f, 0f);
		backWheelInner.render(gl);
		gl.glPopMatrix();
		
		gl.glPopMatrix();
	}
}
