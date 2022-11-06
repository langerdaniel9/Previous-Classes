#include "Grade.h"
#include <math.h>

Grade::Grade()
{
    hw = 50;
    lab = 50;
    project = 50;
    exam = 50;
}

Grade::Grade(double initHW, double initLab, double initProject, double initExam)
{
    hw = initHW;
    lab = initLab;
    project = initProject;
    exam = initExam;
}

double Grade::getHW() { return hw; }
double Grade::getLab() { return lab; }
double Grade::getProject() { return project; }
double Grade::getExam() { return exam; }
void Grade::setHW(double newHW) { hw = newHW; }
void Grade::setLab(double newLab) { lab = newLab; }
void Grade::setProject(double newProject) { project = newProject; }
void Grade::setExam(double newExam) { exam = newExam; }
double Grade::getGrade()
{
    // hw 20%
    // lab 15%
    // project 35%
    // final 30%
    return ((hw * .2) + (lab * .15) + (project * .35) + (exam * .3));
}
