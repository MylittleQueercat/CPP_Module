#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

// 拒绝非法状态，定义什么是不被允许的
// 实现一个不可修改的名称
// 一个有严格取值范围的等级（grade）
// 一组保证该等级始终合法的操作
// 一套在非法状态出现时中断流程的机制
class Bureaucrat
{
	private:  
		const std::string	_name;
		int					_grade;

	public:  
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// getters
		const std::string&	getName() const;
		int					getGrade() const;

		// grade operations
		void	incrementGrade();
		void	decrementGrade();

		// 定义一个只属于Bureaucrat的异常类型
		// exception 异常——控制流机制，用于中断当前执行路径，并跳转到最近的catch
		// 嵌套类（只给Bureaucrat使用）
		class GradeTooHighException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
				// what()是expection定义的一个虚函数，返回类型是const char*
				// 返回一个用于描述异常原因的字符串（题目要求提供具体错误信息）
				// throw是语言关键字，执行就是表达当前函数立刻结束，不再执行后面的
				// catch会接住throw抛出的
		};

		class GradeTooLowException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
		};
	
	private:  
		static void	checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

// 格式
// 返回一个输出流的饮用  <<(输出流对象os类型是std::ostream, 被输出的对象b(使用const表示无法被修改))
// operator<<代表运算符<<
// std::cout << b 等于 operator<<(std::cout, b)
// 当重载运算符时，如果运算符左边的对象是这个类的对象（类型比如Bureaucrat），就可以写进这个类里；否则不能。

#endif