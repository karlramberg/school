package q1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

/**
 * Application to display the time in digital and analog formats
 * @author Karl Ramberg
 */
public class Clock extends JFrame {
	private static final int TIMER_DELAY = 1000;
	private JTextField digital;
	private Timer timer;
	private ClockFace analog;

	/**
	 * Constructor for Clock class
	 */
	public Clock() {
		// set up the digital output
		digital = new JTextField();
		digital.setEditable(false);

		// set up the analog output
		analog = new ClockFace();

		// set up the timer
		timer = new Timer(TIMER_DELAY, new ClockTimer());
		timer.start();

		// set layout and add components
		setLayout(new BorderLayout());
		add(digital, BorderLayout.NORTH);
		add(analog, BorderLayout.CENTER);

		// set other window settings
		pack();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Clock");
		setResizable(false);
		setVisible(true);
	}


	/**
	 * Provides functionality for timing a clock
	 */
	public class ClockTimer implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent actionEvent) {
			// get the current time
			Date now = new Date();

			// update the digital output
			digital.setText(now.toString());

			// update the analog output
			analog.update(now);
		}
	}

	/**
	 * Represents analog output of the time
	 */
	public class ClockFace extends JPanel {
		private final int WIDTH = 600;
		private final int HEIGHT = 600;
		private final int SECOND_HAND_LENGTH = 280;
		private final int SECOND_HAND_WIDTH = 3;
		private final int MINUTE_HAND_LENGTH = 240;
		private final int MINUTE_HAND_WIDTH = 5;
		private final int HOUR_HAND_LENGTH = 160;
		private final int HOUR_HAND_WIDTH = 6;
		private final int ROTATION_AMOUNT = 90;
		private int second;
		private int minute;
		private int hour;
		private JLabel background;

		/**
		 * Constructor for ClockFace
		 */
		public ClockFace() {
			// set the clock background
			background = new JLabel(new ImageIcon("clock_face.jpg"));
			add(background);

			setSize(WIDTH, HEIGHT);
		}

		/**
		 * Draws the clock
		 * @param g the graphics
		 */
		@Override
		public void paint(Graphics g) {
			Graphics2D g2d = (Graphics2D) g;
			super.paint(g2d);

			// x = r * cos(theta)
			// y = r * cos(theta)

			// draw the second hand
			int angle = second * 6 - ROTATION_AMOUNT;
			int secondHandX = (int) (SECOND_HAND_LENGTH * Math.cos(Math.toRadians(angle))) + WIDTH / 2;
			int secondHandY = (int) (SECOND_HAND_LENGTH * Math.sin(Math.toRadians(angle))) + HEIGHT / 2;
			g2d.setColor(Color.RED);
			g2d.setStroke(new BasicStroke(SECOND_HAND_WIDTH));
			g2d.drawLine(WIDTH / 2, HEIGHT / 2, secondHandX, secondHandY);

			// draw the minute hand
			angle = minute * 6 - ROTATION_AMOUNT;
			int minuteHandX = (int) (MINUTE_HAND_LENGTH * Math.cos(Math.toRadians(angle))) + WIDTH / 2;
			int minuteHandY = (int) (MINUTE_HAND_LENGTH * Math.sin(Math.toRadians(angle))) + HEIGHT / 2;
			g2d.setColor(Color.BLACK);
			g2d.setStroke(new BasicStroke(MINUTE_HAND_WIDTH));
			g2d.drawLine(WIDTH / 2, HEIGHT / 2, minuteHandX, minuteHandY);

			// draw the hour hand
			angle = hour * 30 - ROTATION_AMOUNT;
			int hourHandX = (int) (HOUR_HAND_LENGTH * Math.cos(Math.toRadians(angle))) + WIDTH / 2;
			int hourHandY = (int) (HOUR_HAND_LENGTH * Math.sin(Math.toRadians(angle))) + HEIGHT / 2;
			g2d.setStroke(new BasicStroke(HOUR_HAND_WIDTH));
			g2d.drawLine(WIDTH / 2, HEIGHT / 2, hourHandX, hourHandY);
		}

		/**
		 * Updates the time given a date
		 * @param now a Date object for the current time
		 */
		public void update(Date now) {
			this.second = now.getSeconds();
			this.minute = now.getMinutes();
			this.hour = now.getHours();
			if (hour > 12) { // convert to 12-hour time
				hour -= 12;
			}
			repaint();
		}
	}

	public static void main(String[] args) {
		new Clock();
	}
}
