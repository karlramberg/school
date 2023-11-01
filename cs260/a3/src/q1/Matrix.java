package q1;

public class Matrix {

	private double[][] elements;
	
	/**
	 * Constructor for Matric class
	 * @param rows the number of rows in the matrix
	 * @param columns the number of columns in the matrix
	 */
	public Matrix(int rows, int columns) {
		this.elements = new double[rows][columns];
	}
	
	/**
	 * Accessor for elements
	 * @return the 2d array of elements
	 */
	public double[][] getElements() {
		return elements;
	}
	
	/**
	 * Accessor for a specific element in the matrix
	 * @param row the row the element is located
	 * @param column the column the element is located
	 * @return the element at the row and column
	 */
	public double getElement(int row, int column) {
		return this.elements[row][column];
	}
	
	/**
	 * Mutator for a specific element in the matrix
	 * @param row the row where the target is located
	 * @param column the column where the target is located
	 * @param value the value to set the element to
	 */
	public void setElement(int row, int column, double value) {
		this.elements[row][column] = value;
	}
	
	/**
	 * Adds two matrices together
	 * @precondition the current matrix and other are the same size
	 * @param other the matrix to add to the current matrix
	 * @return the resulting matrix
	 */
	public Matrix add(Matrix other) {
		Matrix result = new Matrix(this.elements.length, this.elements[0].length);
		for(int row = 0; row < this.elements.length; row++) {
			for(int column = 0; column < this.elements[0].length; column++) {
				result.setElement(row, column, this.elements[row][column] + other.getElement(row, column));
			}
		}
		return result;
	}
	
	/**
	 * Multiplies two matrices together
	 * @param other the matrix to multiply with the current matrix
	 * @return the resulting matrix
	 */
	public Matrix multiply(Matrix other) {
		Matrix product = new Matrix(this.elements.length, other.getElements()[0].length);
		// do multiplication here
		return product;
	}
}

