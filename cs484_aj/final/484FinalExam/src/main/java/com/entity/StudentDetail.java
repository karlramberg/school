package com.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "student_detail")
public class StudentDetail {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "detail_id")
	private int detail_id;

	@Column(name = "punch_line")
	private String punchLine;

	@Column(name = "hobby")
	private String hobby;

	public StudentDetail() {

	}

	public StudentDetail(String punchLine, String hobby) {
		this.punchLine = punchLine;
		this.hobby = hobby;
	}

	public int getDetail_id() {
		return detail_id;
	}

	public void setDetail_id(int detail_id) {
		this.detail_id = detail_id;
	}

	public String getPunchLine() {
		return punchLine;
	}

	public void setPunchLine(String punchLine) {
		this.punchLine = punchLine;
	}

	public String getHobby() {
		return hobby;
	}

	public void setHobby(String hobby) {
		this.hobby = hobby;
	}

	@Override
	public String toString() {
		return "StudentDetail [detail_id=" + detail_id + ", punchLine=" + punchLine + ", hobby=" + hobby + "]";
	}
}
