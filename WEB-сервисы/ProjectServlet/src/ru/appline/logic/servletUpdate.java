package ru.appline.logic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import ru.appline.Model;
import ru.appline.User;

@WebServlet(urlPatterns = "/update")
public class servletUpdate extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
//	Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletUpdate() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("application/json;charset=utf-8");
		request.setCharacterEncoding("UTF-8");
		
		Model model = Model.getInstance();
		
		PrintWriter pw = response.getWriter();
		int id = Integer.parseInt(request.getParameter("id"));

		StringBuffer stringBuffer = new StringBuffer();
        String line;
        
        try {
            BufferedReader reader = request.getReader();
            while ((line = reader.readLine()) != null) {
                stringBuffer.append(line);
            }
        } catch (Exception e) {
            System.out.println("Error");
        }
        
        JsonObject jsonObject = gson.fromJson(String.valueOf(stringBuffer), JsonObject.class);

        String name = jsonObject.get("name").getAsString();
        String surname = jsonObject.get("surname").getAsString();
        double salary = jsonObject.get("salary").getAsDouble();

        User user = new User(name, surname, salary);
        
        model.update(id, user);
        pw.print(gson.toJson(model.getFromList()));
	}
}
