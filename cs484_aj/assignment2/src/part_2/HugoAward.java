package part_2;

import org.springframework.stereotype.Component;

@Component
public class HugoAward implements Award {
	@Override
	public String getAwardName() {
		return "Hugo Award";
	}

	@Override
	public String getAwardPrizeMoney() {
		return "$10,000";
	}
}
