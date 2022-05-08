package main

import (
	"encoding/csv" //package to read csv files
	"fmt"          //package to print statements in golang
	"os"           //package used to create with files

	"github.com/PuerkitoBio/goquery"
	"github.com/geziyor/geziyor"
	"github.com/geziyor/geziyor/client"
)

func main() {
	csv_details := [][]string{}
	geziyor.NewGeziyor(&geziyor.Options{
		//making request manually
		StartRequestsFunc: func(g *geziyor.Geziyor) {
			g.GetRendered("https://www.forbes.com/real-time-billionaires/#4502d58a3d78", g.Opt.ParseFunc)
			//making a request to the website we want to scrape file from
		},
		ParseFunc: func(gets *geziyor.Geziyor, response *client.Response) {
			response.HTMLDoc.Find("tr.base.ng-scope").Each(func(i int, ele *goquery.Selection) {
				if i <= 9 {
					csv_details = append(csv_details, []string{
						ele.Find("td.rank").Text(),
						ele.Find("td.name").Text(),
						ele.Find("td.Net.Worth").Text(),
						ele.Find("td.age").Text(),
						ele.Find("td.Country\\/Territory").Text(),
						ele.Find("td.source").Text()})
				}
			})

		},
	}).Start()
	file, error := os.Create("Billionaires.csv")
	if error != nil {
		fmt.Println(error)

	}
	defer file.Close()

	csvWriter := csv.NewWriter(file)
	defer csvWriter.Flush() //defer is used to delay the Close() and Flush() call. To close the file just before program terminates

	for _, t := range csv_details {
		_ = csvWriter.Write(t)
		//blank identifier in golang (special feature), helps us to have felxibility
		// (to leave the variable unused)

	}

}
