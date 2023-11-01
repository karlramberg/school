package part_1;

import org.springframework.stereotype.Component;

@Component
public class HugoAward implements Awards {
	@Override
	public String getAwardName() {
		return "Hugo Award";
	}

	@Override
	public String getAwardPrizeMoney() {
		return "$10,000";
	}
}
