package ru.appline.logic;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import ru.appline.Model;

@WebServlet(urlPatterns = "/delete")
public class servletDelete extends HttpServlet {
	
	private static final long serialVersionUID = 6443194703067413751L;
	Model model = Model.getInstance();
	Gson gson = new GsonBuilder().setPrettyPrinting().create();

	/**
     * @see HttpServlet#HttpServlet()
     */
    public servletDelete() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("application/json;charset=utf-8");
		request.setCharacterEncoding("UTF-8");
		
		PrintWriter pw = response.getWriter();
		int id = Integer.parseInt(request.getParameter("id"));
		
		if (id > 0 && model.getFromList().get(id) != null) {
			pw.print(gson.toJson("������������ " +
								model.getFromList().get(id).getName() + 
								" " +
								model.getFromList().get(id).getSurname() + 
								" � ��������� " +
								model.getFromList().get(id).getSalary() +
								" ������."));
			model.delete(id);
			
		} else {
			pw.print(gson.toJson("������������ � ����� ID �� ���������� ��� ID ����� �����������."));
		}
	}

}
