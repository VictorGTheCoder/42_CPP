from selenium import webdriver

def test_firefox_opening():
    driver = webdriver.Firefox()
    driver.get("https://www.google.com")
    driver.quit()

if __name__ == "__main__":
    test_firefox_opening()
