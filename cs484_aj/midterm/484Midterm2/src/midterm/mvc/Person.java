package midterm.mvc;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

public class Person {
	@NotNull(message="Cannot be nothing, enter valid name")
	@Size(min=5, message="More than 4 character is required")
	private String name;
	
	@NotNull(message="Cannot be nothing, enter phone number")
	@Pattern(regexp="660-[0-9]{3}-[0-9]{4}", message="Must be in form 660-XXX-XXXX")
	private String number;	
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number= number;
	}
}
