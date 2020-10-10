package ru.appline.logic;

import java.io.Serializable;
import java.util.Map;
import java.util.HashMap;

public class PetModel implements Serializable {
	
	static final long serialVersionUID = 1L;
	private static final PetModel instance = new PetModel();
	private final Map<Integer, Pet> model;
	
	public PetModel() {
		model = new HashMap<Integer, Pet>();
	}
	
	public static PetModel getInstance() {
		return instance;
	}
	
	public void add(Pet pet, int id) {
		model.put(id, pet);
	}
	
	public Pet getFromList (int id) {
		return model.get(id);
	}
	
	public Map<Integer, Pet> getAll() {
		return model;
	}

	public void delete(int id) {
		model.remove(id);
	}
	
	public void put(int id, Pet pet) {
		model.put(id, pet);
	}
}