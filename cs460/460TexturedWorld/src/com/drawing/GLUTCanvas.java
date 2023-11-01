package com.drawing;

import static com.jogamp.opengl.GL.GL_COLOR_BUFFER_BIT;
import static com.jogamp.opengl.GL.GL_DEPTH_BUFFER_BIT;
import static com.jogamp.opengl.GL.GL_TRIANGLES;
import static com.jogamp.opengl.fixedfunc.GLMatrixFunc.GL_MODELVIEW;
import static com.jogamp.opengl.fixedfunc.GLMatrixFunc.GL_PROJECTION;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.awt.GLCanvas;
import com.jogamp.opengl.glu.GLU;

@SuppressWarnings("serial")
class GLUTCanvas extends GLCanvas implements GLEventListener {
	public static int CANVAS_WIDTH = 1100;
	public static int CANVAS_HEIGHT = 700;
	public static final float DRAWING_WIDTH = 550f;
	public static final float DRAWING_HEIGHT = 350f;
	public static float GL_Width;
	public static float GL_Height;

	GKeyBoard keyboard;
	GMouse mouse;
	GDrawingPoints mousePoints;
	GDrawOrigin origin;
	GPatch backgroud;
	
	GSpriteKey dino;
	GFlag flag;
	GJet jet;
	GCloud cloud;
	GTree tree;
	
	ArrayList<GShape> drawingObjects;
	ArrayList<GCRect> collisionBoxes;

	// Constructor to setup the GUI for this Component
	public GLUTCanvas(GLCapabilities capabilities, GKeyBoard keyboard, GMouse mouse) {
		super(capabilities);

		this.addGLEventListener(this);
		this.setPreferredSize(new Dimension(CANVAS_WIDTH, CANVAS_HEIGHT));
		this.keyboard = keyboard;
	}

	// Called back immediately after the OpenGL context is initialized. Can be used
	// to perform one-time initialization. Run only once.
	@Override
	public void init(GLAutoDrawable drawable) {
		GL2 gl = drawable.getGL().getGL2();
		GLU glu = new GLU();

		GL_Width = DRAWING_WIDTH / 2.0f;
		GL_Height = DRAWING_HEIGHT / 2.0f;
		gl.glMatrixMode(GL_PROJECTION); // choose projection matrix
		gl.glLoadIdentity(); // reset projection matrix
		glu.gluOrtho2D(-GL_Width, GL_Width, -GL_Height, GL_Height);

		// Enable the model-view transform
		gl.glMatrixMode(GL_MODELVIEW); // specify coordinates
		gl.glLoadIdentity(); // reset

		gl.glClearColor(.90f, .90f, 1.0f, 1.0f);
		gl.glColor3f(1.0f, 1.0f, 1.0f);

		mousePoints = new GDrawingPoints(GL_TRIANGLES);

		// Set origin
		origin = new GDrawOrigin(GLUTCanvas.GL_Width, GLUTCanvas.GL_Height);

		// Background textures
		backgroud = new GPatch(-275, -175, 550, 350, 5, "/world/world.png");

		// Load drawingObject file into String array
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("drawingObjects.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		List<String> lines = new ArrayList<String>();
		while (scanner.hasNextLine()) {
			lines.add(scanner.nextLine());
		}
		String[] config = lines.toArray(new String[0]);

		for (int lineNum = 0; lineNum < config.length; lineNum++) {
			String line = config[lineNum];
			if (line.length() != 0) {
				if (line.charAt(0) == '#') {
					if(line.contains("GSpriteKey")) {
						// Intialize Dino
						String[] coords = config[lineNum+1].split(",");
						dino = new GSpriteKey(gl, Integer.parseInt(coords[0]), Integer.parseInt(coords[1]), 100, 90, 85);
						dino.selectAnimation(0);
					} else if(line.contains("GJet")) {
						String[] coords = config[lineNum+1].split(",");
						String textureFile = config[lineNum+2].split(" ")[0];
						jet = new GJet(Float.parseFloat(coords[0]), Float.parseFloat(coords[1]), 50, 25, textureFile);
					} else if(line.contains("GCloud")) {
						String[] coords = config[lineNum+1].split(",");
						String textureFile = config[lineNum+2].split(" ")[0];
						cloud = new GCloud(Float.parseFloat(coords[0]), Float.parseFloat(coords[1]), 100, 50, textureFile);
					} else if(line.contains("GTree")) {
						String[] coords = config[lineNum+1].split(",");
						String textureFile = config[lineNum+2].split(" ")[0];
						tree = new GTree(Float.parseFloat(coords[0]), Float.parseFloat(coords[1]), 100, 100, textureFile);
					} else if(line.contains("GFlag")) {
						String[] coords = config[lineNum+1].split(",");
						String textureFile = config[lineNum+2].split(" ")[0];
						flag = new GFlag(Float.parseFloat(coords[0]), Float.parseFloat(coords[1]), 10, 50, textureFile);
					}
				}
			}
		}

		// Dino collision boxes
		collisionBoxes = new ArrayList<>();
		GCRect box1 = new GCRect(new float[] { .3f, .3f, .3f, -273f, -120f, 140f, 100f });
		collisionBoxes.add(box1);
		GCRect box2 = new GCRect(new float[] { .3f, .3f, .3f, -66f, -94f, 212f, 55f });
		collisionBoxes.add(box2);
		GCRect box3 = new GCRect(new float[] { .3f, .3f, .3f, -15f, -30f, 142f, 78f });
		collisionBoxes.add(box3);
		GCRect box4 = new GCRect(new float[] { .3f, .3f, .3f, -195f, -15f, 105f, 117f });
		collisionBoxes.add(box4);
		GCRect box5 = new GCRect(new float[] { .3f, .3f, .3f, -69f, 53f, 74f, 104f });
		collisionBoxes.add(box5);
		GCRect box6 = new GCRect(new float[] { .3f, .3f, .3f, 34f, 89f, 78f, 78f });
		collisionBoxes.add(box6);
		GCRect box7 = new GCRect(new float[] { .3f, .3f, .3f, 171f, 102f, 104f, 73f });
		collisionBoxes.add(box7);
		dino.setCollisionRectangles(collisionBoxes);

		// Drawing list
		drawingObjects = new ArrayList<GShape>();
		drawingObjects.add(backgroud);
		drawingObjects.add(mousePoints);
		drawingObjects.add(dino);
		drawingObjects.add(flag);
		drawingObjects.add(jet);
		drawingObjects.add(cloud);
		drawingObjects.add(tree);
	}

	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
		GL2 gl = drawable.getGL().getGL2();

		// Window scaling
		// Found at https://forum.jogamp.org/canvas-not-filling-frame-td4040092.html
		double dpiScalingFactorX = ((Graphics2D) getGraphics()).getTransform().getScaleX();
		double dpiScalingFactorY = ((Graphics2D) getGraphics()).getTransform().getScaleY();
		width = (int) (width / dpiScalingFactorX);
		height = (int) (height / dpiScalingFactorY);

		// Print window dimensions if debug enabled
		if (DrawWindow.DEBUG_OUTPUT)
			System.out.println(width + ":" + height);

		GLUTCanvas.CANVAS_HEIGHT = height;
		GLUTCanvas.CANVAS_WIDTH = width;

		// we want this aspect ratio in our drawing
		float targetAspect = DRAWING_WIDTH / DRAWING_HEIGHT;
		if (height < 1)
			height = 1;

		// Calculate aspect ratio
		float calcAspect = (float) width / (float) height;
		float aspect = calcAspect / targetAspect;

		if (calcAspect >= targetAspect) {
			GL_Width = DRAWING_WIDTH / 2.0f * aspect;
			GL_Height = DRAWING_HEIGHT / 2.0f;
		} else {
			GL_Width = DRAWING_WIDTH / 2.0f;
			GL_Height = DRAWING_HEIGHT / 2.0f / aspect;
		}

		origin.updateOriginVertex(GLUTCanvas.GL_Width, GLUTCanvas.GL_Height);

		GLU glu = new GLU();
		gl.glMatrixMode(GL_PROJECTION); // choose projection matrix
		gl.glLoadIdentity(); // reset projection matrix
		glu.gluOrtho2D(-GL_Width, GL_Width, -GL_Height, GL_Height); // canvas

		gl.glViewport(-(int) GL_Width, (int) GL_Width, -(int) GL_Height, (int) GL_Height);

		// Enable the model-view transform
		gl.glMatrixMode(GL_MODELVIEW); // specify coordinates
		gl.glLoadIdentity(); // reset

	}

	// Called back by the animator to perform rendering.
	@Override
	public void display(GLAutoDrawable drawable) {
		GL2 gl = drawable.getGL().getGL2(); // get the OpenGL 2 graphics context

		gl.glClearColor(.90f, .90f, 1.0f, 1.0f); // color used to clean the canvas
		gl.glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the canvas with color

		gl.glLoadIdentity(); // reset the model-view matrix

		// myOrigin.render(gl);
		for (GShape artObject : drawingObjects) {
			artObject.render(gl);
		}

		gl.glFlush();
	}

	// Called back before the OpenGL context is destroyed. Release resource such as
	// buffers.
	@Override
	public void dispose(GLAutoDrawable drawable) {
	}

	// This function updates drawing based on keyboard events
	public void processKeyBoardEvents(int key) {
		this.dino.processKeyBoardEvent(key);
	}

	public void processKeyBoardEventsStop() {
		keyboard.setPressReleaseStatus(false);
		this.dino.resetKeyBoardEvent();
	}
}