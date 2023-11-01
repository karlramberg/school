package midterm.mvc;

import javax.validation.Valid;

import org.springframework.beans.propertyeditors.StringTrimmerEditor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/person")
public class PersonController {
	@RequestMapping("/showForm")
	public String showForm(Model model) {
		Person person = new Person();
		model.addAttribute("person", person);
		return "person-form";
	}

	@RequestMapping("/processForm")
	public String processForm(@Valid @ModelAttribute("person") Person person, BindingResult bindingResult) {
		if (bindingResult.hasErrors())
			return "person-form";
		else
			return "person-confirmation";
	}

	@InitBinder
	public void initBinder(WebDataBinder dataBinder) {
		// the class below is defined in Spring API, removes leading/trailing
		// whitespaces
		// true means set to null if all are white spaces
		StringTrimmerEditor stringTrimmerEditor = new StringTrimmerEditor(true);
		// preprocess every String form data
		dataBinder.registerCustomEditor(String.class, stringTrimmerEditor);
	}
}
