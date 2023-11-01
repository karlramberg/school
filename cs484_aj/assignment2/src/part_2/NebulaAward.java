package part_2;

public class NebulaAward implements Award {
	@Override
	public String getAwardName() {
		return "Nebula Award";
	}

	@Override
	public String getAwardPrizeMoney() {
		return "$1,000";
	}
}
