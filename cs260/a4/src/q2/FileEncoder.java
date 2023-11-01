package q2;

import java.io.*;

/**
 * FileEncoder handles encoding or decoding any file regardless of type
 * @author Karl Ramberg
 */
public class FileEncoder {
	private static final String ENCODED_EXTENSION = ".encoded";
	private File file;

	/**
	 * Constructor for FileEncoder
	 * @param file the file for encoding or decoding
	 */
	public FileEncoder(File file) {
		this.file = file;
	}

	/**
	 * encodes a file by flipping all the bits
	 * @throws IOException
	 */
	public void encodeFile() throws IOException {
		byte[] bytes = fileToByteArray();
		for (int index = 0; index < bytes.length; index++) {
			bytes[index] = (byte) -bytes[index];
		}
		writeBytesToFile(bytes, true);
	}

	/**
	 * decodes a file by flipping all the bits back
	 * @throws IOException
	 */
	public void decodeFile() throws IOException {
		byte[] bytes = fileToByteArray();
		for (int index = 0; index < bytes.length; index++) {
			bytes[index] = (byte) -bytes[index];
		}
		writeBytesToFile(bytes, false);
	}

	/**
	 * opens a file and converts it to raw bytes
	 * @return the file in raw bytes
	 */
	private byte[] fileToByteArray() throws IOException {
		byte[] bytes = new byte[(int) file.length()];
		FileInputStream inputStream = new FileInputStream(file);
		inputStream.read(bytes);
		inputStream.close();
		return bytes;
	}

	/**
	 * Takes raw bytes in an array and writes them to a file
	 * @param bytes the raw bytes to write
	 * @param encoded whether the file should be marked encoded
	 * @throws IOException
	 */
	private void writeBytesToFile(byte[] bytes, boolean encoded) throws IOException {
		String path;
		if (encoded) {
			path = file.getPath() + ENCODED_EXTENSION;
		} else {
			path = file.getPath().substring(0, file.getPath().length() - ENCODED_EXTENSION.length());
		}
		FileOutputStream outputStream = new FileOutputStream(new File(path));
		outputStream.write(bytes);
		outputStream.close();
	}

	/**
	 * Accessor for file
	 * @return the current file for encoding or decoding
	 */
	public File getFile() {
		return file;
	}

	/**
	 * Mutator for file
	 * @param file the new file for encoding or decoding
	 */
	public void setFile(File file) {
		this.file = file;
	}
}
