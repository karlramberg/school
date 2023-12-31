package com.drawing;

import static com.jogamp.opengl.GL.GL_FRONT_AND_BACK;
import static com.jogamp.opengl.GL2GL3.GL_FILL;
import static com.jogamp.opengl.GL2GL3.GL_LINE;

import com.jogamp.opengl.GL2;

public class GEllipse implements GShape {

	float x_radius;
	float y_radius;
	float x, y;
	int numSegments;
	float color[];

	GEllipse(float x, float y, float xr, float yr) {
		this.x_radius = xr;
		this.y_radius = yr;
		this.x = x;
		this.y = y;

		numSegments = 32;

		color = new float[] { 0.133f, 0.545f, 0.100f, 0.133f, 0.545f, 0.1f };
	}

	void setColor(float color[]) {
		this.color = color;
	}

	public void drawOutline(final GL2 gl) {
		gl.glColor3fv(this.color, 3);

		gl.glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		gl.glLineWidth(4f);

		gl.glBegin(GL2.GL_LINE_LOOP);


		float anglePerSegment = 2.0f * (float) Math.PI / numSegments;
		float angle = 0f, nx = 0, ny = 0;
		for (int i = 0; i < numSegments; i++) { // Last vertex same as first vertex
			angle = i * anglePerSegment;
			nx = (float) Math.cos(angle) * this.x_radius;
			ny = (float) Math.sin(angle) * this.y_radius;
			gl.glVertex2f(this.x + nx, this.y + ny);
		}
		gl.glEnd();
	}


	public void render(final GL2 gl) {
		gl.glColor3fv(this.color, 0);

		gl.glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		gl.glBegin(GL2.GL_TRIANGLE_FAN);

		gl.glVertex2f(this.x, this.y); // Center of circle


		float anglePerSegment = 2.0f * (float) Math.PI / numSegments;
		float angle = 0f, nx = 0, ny = 0;
		for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
			angle = i * anglePerSegment;
			nx = (float) Math.cos(angle) * this.x_radius;
			ny = (float) Math.sin(angle) * this.y_radius;
			gl.glVertex2f(this.x + nx, this.y + ny);
		}
		gl.glEnd();
		drawOutline(gl);

	}
}
