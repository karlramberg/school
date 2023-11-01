package part_1;

import org.springframework.stereotype.Component;

@Component
public class President implements Person {
	@Override
	public String getPersonName() {
		return "Sue Thomas";
	}
}
