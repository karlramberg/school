package main;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 * Basic calculator that supports binary operations
 * @author Karl Ramberg
 */
public class Calculator extends JFrame {
	private static final int TOTAL_WIDTH = 400;
	private static final int TOTAL_HEIGHT = 400;
	private static final int OUTPUT_WIDTH = 20;
	private static final int BUTTON_PANEL_WIDTH = 4;
	private static final int BUTTON_PANEL_HEIGHT = 4;
	private static final Color TEXT_COLOR = Color.WHITE;
	private static final Color BACKGROUND_COLOR = Color.BLUE;
	private static final Color ERROR_COLOR = Color.RED;

	private JPanel buttonPanel;
	private JButton buttons[];
	private final String captions[] = {"1", "2", "3", "/", "AC",
			"4", "5", "6", "*", "BKSP",
			"7", "8", "9", "-", "SQRT",
			"0", "", "", "+", "="};
	private JTextField output;

	/**
	 * Constructor for Calculator class
	 */
	public Calculator() {
		// create and initialize all the buttons in the panel
		buttons = new JButton[captions.length];
		buttonPanel = new JPanel(new GridLayout(BUTTON_PANEL_WIDTH, BUTTON_PANEL_HEIGHT));
		ButtonListener buttonListener = new ButtonListener();
		for (int index = 0; index < buttons.length; index++) {
			// create a new button and add the corresponding caption
			buttons[index] = new JButton(captions[index]);
			buttons[index].addActionListener(buttonListener);
			buttons[index].setBackground(BACKGROUND_COLOR);
			buttons[index].setForeground(TEXT_COLOR);
			// disable the button if it is empty
			if (buttons[index].getText() == "") {
				buttons[index].setEnabled(false);
			}

			// add the button to the panel
			buttonPanel.add(buttons[index]);
		}

		// create and intialize the output field
		output = new JTextField(OUTPUT_WIDTH);
		output.setEditable(false);
		output.setBackground(BACKGROUND_COLOR);
		output.setForeground(TEXT_COLOR);

		// set the frame layout and add components
		setLayout(new BorderLayout());
		add(output, BorderLayout.NORTH);
		add(buttonPanel, BorderLayout.CENTER);

		// set additional settings for the frame
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(TOTAL_WIDTH, TOTAL_HEIGHT);
		setVisible(true);
	}

	/**
	 * Handler for the calculator's buttons
	 */
	public class ButtonListener implements ActionListener {
		/**
		 * listener for every button, creates and evaluates mathematical strings
		 * @param actionEvent information for the button press that occured
		 */
		@Override
		public void actionPerformed(ActionEvent actionEvent) {
			output.setForeground(TEXT_COLOR);
			String caption = actionEvent.getActionCommand();
			switch (caption) {
				case "1":
				case "2":
				case "3":
				case "/":
				case "4":
				case "5":
				case "6":
				case "*":
				case "7":
				case "8":
				case "9":
				case "-":
				case "0":
				case "+":
					// add the digit or operator to the output
					output.setText(output.getText() + caption);
					break;
				case "AC":
					// clear the output
					output.setText("");
					break;
				case "BKSP":
					// remove one character from the output
					int outputLength = output.getText().length();
					if (outputLength != 0) {
						output.setText(output.getText().substring(0, outputLength - 1));
					}
					break;
				case "SQRT":
					// calculate the square root of the number in the output
					try {
						int number = Integer.parseInt(output.getText());
						output.setText(((int) Math.sqrt(number)) + "");
					} catch (NumberFormatException numberFormatException) {
						// signal an incorrect expression by turning the text red
						output.setForeground(ERROR_COLOR);
					}
					break;
				case "=":
					// Evaulate the output as an arthimatic expression with a maximum of two operands
					String expression = output.getText();

					// find the location of the operator
					int operatorIndex = findOperator(expression);
					try {
						// parse either side of the operator for an integer to find operands
						int operand1 = Integer.parseInt(expression.substring(0, operatorIndex));
						int operand2 = Integer.parseInt(expression.substring(operatorIndex + 1, expression.length()));

						// calculate the expression with the appropriate operator
						if (expression.charAt(operatorIndex) == '+') {
							output.setText(operand1 + operand2 + "");
						} else if (expression.charAt(operatorIndex) == '-') {
							output.setText(operand1 - operand2 + "");
						} else if (expression.charAt(operatorIndex) == '*') {
							output.setText(operand1 * operand2 + "");
						} else if (expression.charAt(operatorIndex) == '/') {
							if (operand2 == 0) { // don't divide by zero
								output.setForeground(ERROR_COLOR);
							} else {
								output.setText(operand1 / operand2 + "");
							}
						}
					} catch (NumberFormatException numberFormatExpression) {
						// operand(s) could not be parsed properly, signal user with red text
						output.setForeground(ERROR_COLOR);
					}
					break;
				default:
					break;
			}
		}

		/**
		 * Given a string representing a mathematical expression, find the first occurence of an operator (e.g. +, -, *, /)
		 * @param expression the expression to search
		 * @return the index of the found operator
		 */
		private int findOperator(String expression) {
			// run through the string, return when one of four operators in found (+, -, *, /)
			for (int index = 0; index < expression.length(); index++) {
				char character = expression.charAt(index);
				if (character == '+' || character == '*' || character == '/') {
					return index;
				} else if (character == '-') {
					if (index != 0) { // ignore in the first slot, this is a unary negation
						return index;
					}
				}
			}
			// operator was not found, signal error with red text
			output.setForeground(ERROR_COLOR);
			return 0;
		}
	}

	public static void main(String[] arguments) {
		new Calculator();
	}
}