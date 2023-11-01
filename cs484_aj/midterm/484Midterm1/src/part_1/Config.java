package part_1;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan
public class Config {
	@Bean
	public TrumanState getTrumanState() {
		return new TrumanState();
	}
}
