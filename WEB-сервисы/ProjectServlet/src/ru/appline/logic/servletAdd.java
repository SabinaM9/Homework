package ru.appline.logic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.atomic.AtomicInteger;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import ru.appline.Model;
import ru.appline.User;


@WebServlet(urlPatterns = "/add")
public class servletAdd extends HttpServlet{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -8436985916739553979L;
	
	private AtomicInteger counter = new AtomicInteger(4);
	Model model = Model.getInstance();
	Gson gson = new GsonBuilder().setPrettyPrinting().create();
	
//	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
//		response.setContentType("text/html;charset=UTF-8");
//		
//		request.setCharacterEncoding("UTF-8");
//		
//		PrintWriter pw = response.getWriter();
//
//		String name = request.getParameter("name");
//		String surname = request.getParameter("surname");
//		double salary = Double.parseDouble(request.getParameter("salary"));
//		
//		User user = new User(name, surname, salary);
//		model.add(counter.getAndIncrement(), user);
//		
//		pw.print("<html>" +
//				"<h3>������������ " + name + " " + surname + " � ��������� = " + salary + " ������� ������! :) </h3>" +
//				"<a href=\"addUser.html\">������� ������ ������������</a><br/>" +
//				"<a href=\"index.jsp\">�����</a>" +
//				"</html>");
//	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
		
		response.setContentType("application/json;charset=utf-8");
		request.setCharacterEncoding("UTF-8");
		
		StringBuffer jb = new StringBuffer();
		String line;
		
		try {
			BufferedReader reader = request.getReader();
			while ((line = reader.readLine()) !=null) {
				jb.append(line);
			}
		} catch (Exception e) {
			System.out.println("Error");
		}
		
		JsonObject jobj = gson.fromJson(String.valueOf(jb), JsonObject.class);
		
		String name = jobj.get("name").getAsString();
		String surname = jobj.get("surname").getAsString();
		double salary = jobj.get("salary").getAsDouble();
		
		User user = new User(name, surname, salary);
		model.add(counter.getAndIncrement(), user);
		
		PrintWriter pw = response.getWriter();
		pw.print(gson.toJson(model.getFromList()));
	}
}