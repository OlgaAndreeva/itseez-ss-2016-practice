#pragma once

#include <memory>
#include <string>

#include "opencv2/core/core.hpp"
#include "opencv2/objdetect.hpp"

using namespace cv;

class Detector {
 public:
	 static std::shared_ptr<Detector> CreateDetector(const std::string& name);
	 virtual bool Init(const std::string& model_file_path) = 0;
	 void Detect(const cv::Mat& frame, std::vector<cv::Rect>& objects,
		 std::vector<double>& scores) {};
};

class CascadeDetector : public Detector {
public:
	bool Init(const std::string& model_file_path);
	void Detect(const cv::Mat& frame, std::vector<cv::Rect>& objects,
		std::vector<double>& scores);
	std::vector<double> scores;

protected:
	cv::CascadeClassifier detector;
	
};