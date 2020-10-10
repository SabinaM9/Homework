package ru.appline.logic;

import java.io.Serializable;
import java.util.Map;

public class Compas implements Serializable {

private static final long serialVersionUID = -4763293050377186448L;
	
	public static int[] a1 = new int[2];	//[Integer, Integer]
	public static int[] a2 = new int[2];
	public static int[] a3 = new int[2];
	public static int[] a4 = new int[2];
	public static int[] a5 = new int[2];
	public static int[] a6 = new int[2];
	public static int[] a7 = new int[2];
	public static int[] a8 = new int[2];
	
	public void saveCompas(Map<String, String> compas) {
		
			String list_1 = compas.get("North");		// "360-0"
			String list_2 = compas.get("North-East");
			String list_3 = compas.get("East");
			String list_4 = compas.get("South-East");
			String list_5 = compas.get("South");
			String list_6 = compas.get("South-West");
			String list_7 = compas.get("West");
			String list_8 = compas.get("North-West");
			
			String[] list_1s = list_1.split("-", 2);	//["360", "0"]
			String[] list_2s = list_2.split("-", 2);
			String[] list_3s = list_3.split("-", 2);
			String[] list_4s = list_4.split("-", 2);
			String[] list_5s = list_5.split("-", 2);
			String[] list_6s = list_6.split("-", 2);
			String[] list_7s = list_7.split("-", 2);
			String[] list_8s = list_8.split("-", 2);
			
			a1[0] = Integer.parseInt(list_1s[0]);
			a2[0] = Integer.parseInt(list_2s[0]);
			a3[0] = Integer.parseInt(list_3s[0]);
			a4[0] = Integer.parseInt(list_4s[0]);
			a5[0] = Integer.parseInt(list_5s[0]);
			a6[0] = Integer.parseInt(list_6s[0]);
			a7[0] = Integer.parseInt(list_7s[0]);
			a8[0] = Integer.parseInt(list_8s[0]);
			
			a1[1] = Integer.parseInt(list_1s[1]);
			a2[1] = Integer.parseInt(list_2s[1]);
			a3[1] = Integer.parseInt(list_3s[1]);
			a4[1] = Integer.parseInt(list_4s[1]);
			a5[1] = Integer.parseInt(list_5s[1]);
			a6[1] = Integer.parseInt(list_6s[1]);
			a7[1] = Integer.parseInt(list_7s[1]);
			a8[1] = Integer.parseInt(list_8s[1]);
	}
}
