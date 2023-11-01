package part_1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class FourYearCollege {
	@Autowired
	private President president;
	
	private TrumanState trumanState;

	public String getPresidentName() {
		return president.getPersonName();
	}

	public String getTrumanStateName() {
		return trumanState.getUniversityName();
	}
}
