package part_1;

import org.springframework.stereotype.Component;

@Component
public class TrumanState implements University {
	@Override
	public String getUniversityName() {
		return "Truman State University";
	}
}
