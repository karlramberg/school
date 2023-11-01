package com.drawing;

import static com.jogamp.opengl.GL.GL_COLOR_BUFFER_BIT;
import static com.jogamp.opengl.fixedfunc.GLMatrixFunc.GL_MODELVIEW;
import static com.jogamp.opengl.fixedfunc.GLMatrixFunc.GL_PROJECTION;

import java.awt.Dimension;
import java.util.ArrayList;

import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.awt.GLCanvas;

@SuppressWarnings("serial")
class GLUTCanvas extends GLCanvas implements GLEventListener {

	private static final int CANVAS_WIDTH = 1000; // width of the drawable
	private static final int CANVAS_HEIGHT = 700; // height of the drawable

	private final float DRAWING_WIDTH = 100f, DRAWING_HEIGHT = 100f;

	private GCircle landscape;
	private GCircle sun;
	private GRocket rocket;
	private GCloud small_cloud;
	private GCloud big_cloud;
	private GJet jet;
	private GHome home;
	private GFlag flag;
	private GTree tree;
	private GQuad tracks;
	private GTrain train;
	private GWagon wagon;

	ArrayList<GShape> drawingObjects;

	/** Constructor to setup the GUI for this Component */
	public GLUTCanvas() {
		this.addGLEventListener(this);
		this.setPreferredSize(new Dimension(CANVAS_WIDTH, CANVAS_HEIGHT));

	}

	// ------ Implement methods declared in GLEventListener ------

	/**
	 * 
	 * Called back immediately after the OpenGL context is initialized. Can be used
	 * to perform one-time initialization. Run only once.
	 */
	@Override
	public void init(GLAutoDrawable drawable) {
		GL2 gl = drawable.getGL().getGL2(); // get the OpenGL graphics context
		gl.glMatrixMode(GL_PROJECTION); // choose projection matrix
		gl.glLoadIdentity(); // reset projection matrix
		gl.glOrtho(0.0f, DRAWING_WIDTH, 0.0f, DRAWING_HEIGHT, -1.0f, 0.0f); // 2D canvas

		// Enable the model-view transform
		gl.glMatrixMode(GL_MODELVIEW); // specify coordinates
		gl.glLoadIdentity(); // reset

		// Clear the canvas by drawing light blue sky
		gl.glClearColor(0.529f, 0.808f, 0.980f, 1.0f); 
		
		// Draw the landscape as a large circle centered well below
		landscape = new GCircle(70f, -170f, 210f, 2048);
		// Set the landscape's color to green
		float landscape_color[] = { 0.420f, 0.557f, 0.137f, 0.420f, 0.557f, 0.137f };
		landscape.setColor(landscape_color);

		// Draw a yellow circle for the sun
		sun = new GCircle(135f, 90f, 5f, 32);
		float sun_color[] = { 0.941f, 0.902f, 0.549f, 0.941f, 0.902f, 0.549f };
		sun.setColor(sun_color);
		
		// Draw a rocket
		rocket = new GRocket(120f, 30f);
		
		// Draw two clouds
		small_cloud = new GCloud(-10f, 75f, 3f);
		big_cloud = new GCloud(-40f, 88f, 5f);
	
		// Draw a super fast cool jet
		jet = new GJet(-10.0f, 90f);
		
		// Draw the house
		home = new GHome(25f, 55f);
	
		// Draw a flag
		flag = new GFlag(90f, 35f);
		
		// Draw the tree
		tree = new GTree(10f, 30f);
		
		// Draw the train tracks
		float track_vertices[] = { 0f, 10f,            // top left
								   150f, 8f,          // bottom right
								   0.2f, 0.2f, 0.2f,   // main color
								   0.2f, 0.2f, 0.2f }; // outline color
		tracks = new GQuad(track_vertices);
		
		// Draw the train
		train = new GTrain(-32f, 14f);
		
		// Draw the train wagon
		wagon = new GWagon(-57f, 14f);
	
		
		// Initialize and add the objects to the drawing list
		drawingObjects = new ArrayList<GShape>();
		drawingObjects.add(landscape);
		drawingObjects.add(sun);
		drawingObjects.add(rocket);
		drawingObjects.add(small_cloud);
		drawingObjects.add(big_cloud);
		drawingObjects.add(jet);
		drawingObjects.add(home);
		drawingObjects.add(flag);
		drawingObjects.add(tree);
		drawingObjects.add(tracks);
		drawingObjects.add(train);
		drawingObjects.add(wagon);
	}

	/**
	 * Call-back handler for window re-size event. Also called when the drawable is
	 * first set to visible.
	 */
	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {

		GL2 gl = drawable.getGL().getGL2(); // get the OpenGL graphics context
		// ----- Your OpenGL initialization code here -----
		float ar = 1f;
		if (height < 1)
			height = 1;
		ar = width / (float) height;

		gl.glMatrixMode(GL_PROJECTION); // choose projection matrix
		gl.glLoadIdentity(); // reset projection matrix
		gl.glOrtho(0.0f, DRAWING_WIDTH * ar, 0.0f, DRAWING_HEIGHT, -1.0f, 0.0f); // 2D canvas

		// Enable the model-view transform
		gl.glMatrixMode(GL_MODELVIEW); // specify coordinates
		gl.glLoadIdentity(); // reset

	}

	/**
	 * Called back by the animator to perform rendering.
	 */
	@Override
	public void display(GLAutoDrawable drawable) {
		GL2 gl = drawable.getGL().getGL2(); // get the OpenGL 2 graphics context
		gl.glClear(GL_COLOR_BUFFER_BIT); // clear the canvas with color
		gl.glLoadIdentity(); // reset the model-view matrix

		gl.glTranslatef(0.0f, 0.0f, 0.0f); // translate into the screen

		for (GShape artObject : drawingObjects) {
			artObject.render(gl);
		}

		gl.glFlush();
	}

	/**
	 * Called back before the OpenGL context is destroyed. Release resource such as
	 * buffers.
	 */
	@Override
	public void dispose(GLAutoDrawable drawable) {
	}
}