package q2;

import java.util.Scanner;

/**
 * InvoiceDriver is a simple executable class for testing the
 * functionality of the Invoice class
 * @author karl
 */
public class InvoiceDriver {
	public static void main(String[] args)
	{
		// Print the default invoice
		Invoice defaultInvoice = new Invoice();
		System.out.println("Default Invoice");
		System.out.println("Part Number: " + defaultInvoice.getPartNumber());
		System.out.println("Description: " + defaultInvoice.getDescription());
		System.out.println("Quantity: " + defaultInvoice.getQuantity());
		System.out.println("Price: $" + defaultInvoice.getPrice());
		System.out.println("Amount: $" + defaultInvoice.getInvoiceAmount());
		System.out.println("");
		
		// Ask the user for custom values to show-case the argument constructor
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter a part number: ");
		String partNumber = scanner.nextLine();
		
		System.out.print("Enter a description: ");
		String description = scanner.nextLine();
		
		System.out.print("Enter a quanity: ");
		int quantity = scanner.nextInt();
		
		System.out.print("Enter a price: ");
		double price = scanner.nextDouble();
		System.out.println("");
		
		// Print out the custom invoice
		Invoice customInvoice = new Invoice(partNumber, description, quantity, price);
		System.out.println("Custom Invoice");
		System.out.println("Part Number: " + customInvoice.getPartNumber());
		System.out.println("Description: " + customInvoice.getDescription());
		System.out.println("Quantity: " + customInvoice.getQuantity());
		System.out.println("Price: $" + customInvoice.getPrice());
		System.out.println("Amount: $" + customInvoice.getInvoiceAmount());

		System.out.println("");
		
		// Ask the user for new values to show-case setters
		System.out.print("Enter a part number: ");
		String dummy = scanner.nextLine(); // eats a newline
		partNumber = scanner.nextLine();
		customInvoice.setPartNumber(partNumber);
		
		System.out.print("Enter a description: ");
		description = scanner.nextLine();
		customInvoice.setDescription(description);
		
		System.out.print("Enter a quanity: ");
		quantity = scanner.nextInt();
		customInvoice.setQuantity(quantity);
		
		System.out.print("Enter a price: ");
		price = scanner.nextDouble();
		customInvoice.setPrice(price);
		System.out.println("");
		
		// Print out the new custom invoice
		System.out.println("New Custom Invoice");
		System.out.println("Part Number: " + customInvoice.getPartNumber());
		System.out.println("Description: " + customInvoice.getDescription());
		System.out.println("Quantity: " + customInvoice.getQuantity());
		System.out.println("Price: $" + customInvoice.getPrice());
		System.out.println("Amount: $" + customInvoice.getInvoiceAmount());
		System.out.println("");
	}
}
