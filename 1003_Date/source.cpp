class Date {
 public:
  explicit Date(int year, int month, int day);

  Date& operator++();
  Date operator++(int);

  bool operator==(const Date& rhs);
  bool operator!=(const Date& rhs);
  bool operator>(const Date& rhs);
  bool operator<(const Date& rhs);

  // Format: "Year-Month-Day", like: "2013-6-28", don't need to wrap(换行).
  friend ostream& operator<<(ostream& os, const Date& date);

 private:
  int year_;
  int month_;
  int day_;
};

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year) {
  if (year % 4)
    return false;
  if (!(year % 400))
    return true;
  if (!(year % 100))
    return false;
  return true;
}

Date::Date(int year, int month, int day)
    : year_(year),
      month_(month),
      day_(day) {}

Date& Date::operator++() {
  if (isLeapYear(year_))
    daysInMonth[1] = 29;
  else
    daysInMonth[1] = 28;

  day_++;
  if (day_ > daysInMonth[month_ - 1]) {
    month_++;
    if (month_ > 12) {
      year_++; 
      month_ = 1;
    }
    day_ = 1;
  }

  return *this;
}

Date Date::operator++(int) {
  Date tmp = *this;
  ++(*this);

  return tmp;
}

bool Date::operator==(const Date& rhs) {
  return ((year_ == rhs.year_) && (month_ == rhs.month_) && (day_ == rhs.day_));
}

bool Date::operator!=(const Date& rhs) {
  return !(*this == rhs);
}

bool Date::operator>(const Date& rhs) {
  if (year_ > rhs.year_)
    return true;
  else if (year_ < rhs.year_)
    return false;
  else {
    if (month_ > rhs.month_)
      return true;
    else if (month_ < rhs.month_)
      return false;
    else 
      return day_ > rhs.day_;
  }
}

bool Date::operator<(const Date& rhs) {
  return !((*this) > rhs) && ((*this) != rhs);
}

ostream& operator<<(ostream& os, const Date& date) {
  os << date.year_ << "-" << date.month_ << "-" << date.day_;
  return os;
}
