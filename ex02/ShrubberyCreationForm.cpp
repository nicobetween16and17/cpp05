#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("blank", 145, 137){
	std::cout << *this << "created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(int name): AForm(name, 145, 137){
	std::cout << *this << "created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c) : AForm(c){
	std::cout << *this << "created\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << *this << "deleted\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &e){
	this->_name = e._name;
	this->_signed = e._signed;
	std::cout << e << "copied\n";
}

ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	if ((const int)executor.getGrade() > this->_gradeToX)
		throw (AForm::GradeTooLowException());
	else
	{
		std::string treeName(executor.getName());

		treeName.append("_shrubbery");
		std::ofstream tree(treeName, std::ofstream::out);
		this->_signed = true;
		tree << "                                                        ,\n"
		"                                            .__ ._       \\_.          \n"
		"                                     _, _.  '  \\/   \\.-  /            \n"
		"                                      \\/     .-_`   // |/     \\,      \n"
		"                     .-\"\"\"\"-.          \\.   '   \\`. ||  \\.-'  /       \n"
		"                    F        Y        .-.`-(   _/\\ V/ \\\\//,-' >-'   ._,\n"
		"                   F          Y   .__/   `. \\.   ' J   ) ./  / __._/  \n"
		"                  J         \\, I    '   _/ \\  \\  | |  / /  .'-'.-' `._,\n"
		"           (       L   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\ \n"
		"         \\ '\\    .  L   /    \\\\/        ._/`-.`  \\ .'.' .'---./__   ' \n"
		"    \\__  '\\ ) \\._/   `-.__. ` \\\\_. '   .---.  \\     /  /  ,   `  `    \n"
		"  --'  \\\\  ): // \\,            `-.`__.'     `- \\  /   / _/-.---.__.- . \n"
		"     _.-`.'/ /'\\_, ._     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`\n"
		" _ .---._\\ \\'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' \\\n"
		" .:' /`\\ `. `..'.--'\\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-\n"
		"     `  `. `\\/'/  _.   _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \\\n"
		"  -._ .--.\\ / /-./     /   .---'-//.___. .-'       \\__ .--.  `    `.     '`-\n"
		" ,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \\ \\    |_.\n"
		"    /' | >.   ' | \\._.-       '    _..'  `.' . `.       )    | |\\  `          \n"
		"  ./ \\ \\'  ) c| /  \\     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\\\            \n"
		"   \\'  / ,-.  | ` ./`  ._/ `\\\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`     \n"
		"______'\\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\. _____\n"
		"a:f        |  |        .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '\n"
		"           >  |      _.  /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__   \n"
		"        . /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-.\n"
		"            '  .:'          '`      '          < `   f  I //        `�\\_,\n"
		"              '                         \\.     J        I/\\_.        ./\n"
		"         __/                            `:     I  .:    K  `          `\n"
		"         \\/ )                            `,   J         L             \n"
		"          )_(_                             .  F  .-'    J             \n"
		"         /    `.                           .  I  (.   . I _.-.._      \n"
		"   '    <'    \\ )                     _.---.J/      :'   L -'         \n"
		" .:.     \\. _.->/                        _.-'_.)     ` `-.`---.,_.    \n"
		":<        (    \\                    .--\"\"   .F' J) `.`L.__`-.___      \n"
		".:        |-'\\_.|                          Y ..Z     ))   `--'  `-    \n"
		".         ) | > :                            . '    :'                \n"
		"          / ) L_J                            .x,.\n"
		"          L_J .,                             .:<.,  \n"
		"        .'`   `                               :J.,` \n"
		"                                           . ;.+K,:.\n"
		"                                               .,L+.,";
		tree.close();
		}
}
