package ru.appline.logic;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import ru.appline.Model;

@WebServlet(urlPatterns = "/get")
public class servletList extends HttpServlet{

	private static final long serialVersionUID = -2446158267229646401L;
	
	Model model = Model.getInstance();
	Gson gson = new GsonBuilder().setPrettyPrinting().create();
	
//	 protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
//		
//		response.setContentType("application/json;charset=utf-8");
//		request.setCharacterEncoding("UTF-8");
//		
//		StringBuffer jb = new StringBuffer();
//		String line;
//		
//		try {
//			BufferedReader reader = request.getReader();
//			while ((line = reader.readLine()) !=null) {
//				jb.append(line);
//			}
//		} catch (Exception e) {
//			System.out.println("Error");
//		}
//		
//		JsonObject jobj = gson.fromJson(String.valueOf(jb), JsonObject.class);
//		
//		String name = jobj.get("name").getAsString();
//		String surname = jobj.get("surname").getAsString();
//		double salary = jobj.get("salary").getAsDouble();
//		
//		User user = new User(name, surname, salary);
//		model.add(counter.getAndIncrement(), user);
//		
//		PrintWriter pw = response.getWriter();
//		pw.print(gson.toJson(model.getFromList()));
//	} 
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		response.setContentType("application/json;charset=utf-8");
		
		PrintWriter pw = response.getWriter();
		int id = Integer.parseInt(request.getParameter("id"));

		if(id == 0) {
			pw.print(gson.toJson(model.getFromList()));
			
		} else if(id > 0) {
			
			if (id > model.getFromList().size() || model.getFromList().get(id) == null) {
				pw.print(gson.toJson("������ ������������ ��� :(" ));
				
			} else {
				pw.print(gson.toJson("����������� ������������: " +
									model.getFromList().get(id).getName() + 
									" " +
									model.getFromList().get(id).getSurname() + 
									" � ��������� " +
									model.getFromList().get(id).getSalary()));
			}
			
		} else {
			pw.print(gson.toJson("ID ������ ���� ������ ����!"));
		}
		
	}
	
}