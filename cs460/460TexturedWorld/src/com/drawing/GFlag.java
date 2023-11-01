package com.drawing;

import static com.jogamp.opengl.GL.GL_CULL_FACE;
import static com.jogamp.opengl.GL.GL_FRONT_AND_BACK;
import static com.jogamp.opengl.GL.GL_TRIANGLE_STRIP;
import static com.jogamp.opengl.GL2GL3.GL_FILL;
import com.jogamp.opengl.GL2;
import com.jogamp.opengl.util.texture.Texture;

public class GFlag implements GShape {
	
	private float scaleFactor;
	private boolean growing;
	private float SCALE_SPEED = 0.001f;
	private float MAX_SCALE = 1.075f;
	private float MIN_SCALE = 0.925f;
	
	private Texture texture;
	private float x;
	private float y;
	private float width;
	private float height;
	
	GFlag(float x, float y, float width, float height, String textureFile) {
		this.scaleFactor = MIN_SCALE;
		this.growing = true;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.texture = GTextureUtil.loadSimpleTexture(textureFile);
	}
	
	@Override
	public void render(GL2 gl) {
		gl.glEnable(GL2.GL_TEXTURE_2D);
		gl.glEnable(GL2.GL_BLEND);
		gl.glBlendFunc(GL2.GL_SRC_ALPHA, GL2.GL_ONE_MINUS_SRC_ALPHA);

		texture.enable(gl);
		texture.bind(gl);

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
		
		gl.glTranslatef(x, y, 0.0f);
		gl.glScalef(width * scaleFactor, height * scaleFactor, 1.0f);
		
		gl.glEnable(GL_CULL_FACE);

		gl.glColor3f(1.0f, 1.0f, 1.0f); // drawing color

		gl.glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		if (texture != null) {
			gl.glEnable(GL2.GL_TEXTURE_2D);
			texture.enable(gl);
			texture.bind(gl);
		}

		gl.glBegin(GL_TRIANGLE_STRIP);

		gl.glTexCoord2f(1, 0);
		gl.glVertex2f(1f, 0f); 
		gl.glTexCoord2f(1, 1);
		gl.glVertex2f(1f, 1f); 
		gl.glTexCoord2f(0, 0);
		gl.glVertex2f(0f, 0f); 
		gl.glTexCoord2f(0, 1);
		gl.glVertex2f(0f, 1f); 

		gl.glEnd();

		if (texture != null) {
			gl.glDisable(GL2.GL_TEXTURE_2D);
			texture.disable(gl);
		}

		gl.glDisable(GL2.GL_BLEND);
		gl.glDisable(GL2.GL_TEXTURE_2D);

		gl.glDisable(GL_CULL_FACE);

		gl.glPopMatrix();
	}
}
