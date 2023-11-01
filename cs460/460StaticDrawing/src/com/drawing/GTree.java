package com.drawing;

import com.jogamp.opengl.GL2;

public class GTree implements GShape {

	private GEllipse leaves;
	private GQuad trunk;
	private GCircle fruit1;
	private GCircle fruit2;
	private GCircle fruit3;
	
	GTree(float x, float y) {
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
		fruit1 = new GCircle(x - 2f, y + 45f, 2f);
		fruit2 = new GCircle(x + 6f, y + 50f, 2f);
		fruit3 = new GCircle(x + 1f, y + 60f, 2f);
		fruit1.setColor(fruitColor);
		fruit2.setColor(fruitColor);
		fruit3.setColor(fruitColor);
	}
	
	@Override
	public void render(GL2 gl) {
		trunk.render(gl);
		leaves.render(gl);
		fruit1.render(gl);
		fruit2.render(gl);
		fruit3.render(gl);
	}
}
