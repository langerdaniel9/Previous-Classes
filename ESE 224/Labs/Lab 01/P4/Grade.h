#pragma

class Grade
{
private:
    double hw, lab, project, exam;

public:
    Grade();
    Grade(double initHW, double initLab, double initProject, double initExam);
    double getHW();
    double getLab();
    double getProject();
    double getExam();
    void setHW(double newHW);
    void setLab(double newLab);
    void setProject(double newProject);
    void setExam(double newExam);
    double getGrade();
};
