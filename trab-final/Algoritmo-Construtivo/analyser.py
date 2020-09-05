import os
import json
import csv



if __name__=="__main__":

    input_local = "./results/tests-ed-2020/"
    output_local = "./results/tests-ed-2020-analysis/"

    output_file = "resumo.csv"

    trials = [i for i in range(5)]

    all_files = os.popen("ls " + input_local).read().strip().splitlines()

    result_files = []

    for trial_name in all_files:
        list_name = trial_name.split(".")[0]
        list_name = list_name.split("-")[:-1]

        file_name = ""
        for sub_string in list_name:
            file_name += sub_string + "-"

        file_name = file_name[:-1]

        if (file_name not in result_files):
            result_files.append(file_name)


    dict_resume = {}

    for file_name in result_files:

        dict_resume[file_name] = {
            "name":file_name + ".json",
            "number_connex": 0,
            "number_bal": 0,
            "avg_time" : 0,
            "avg_diameter": 0,
            "avg_imbalance": 0
        }
        

        for trial in trials:
            trial_complete_path = ""
            trial_complete_path += input_local + file_name 
            trial_complete_path += "-" + str(trial) + ".json"
            with open(trial_complete_path, "r") as f:
                dict_result = json.load(f)

                tempo_exec = float(dict_result["tempo_execucao"])
                connex = True
                if (dict_result["distritos_conexos"] == "False"):
                    connex = False
                

                is_balanced = False
                if (dict_result["solucao_balanceada"] == "True"):
                    is_balanced = True
                
                diameter = float(dict_result["solucao_diametro"])

                imbalances = dict_result["desbalanceamento_distritos"]

                total_imabalance = 0
                for key, value in imbalances.items():
                    total_imabalance += float(value)

                if (connex):
                    dict_resume[file_name]["number_connex"] += 1
                
                if (is_balanced):
                    dict_resume[file_name]["number_bal"] += 1
                
                dict_resume[file_name]["avg_time"] += tempo_exec
                dict_resume[file_name]["avg_diameter"] += diameter
                dict_resume[file_name]["avg_imbalance"] += total_imabalance

        avg_time = (
            dict_resume[file_name]["avg_time"] 
            / len(trials)
        )
        
        avg_diameter = (
            dict_resume[file_name]["avg_diameter"] 
            / len(trials)
        )
        
        avg_imbalance = (
            dict_resume[file_name]["avg_imbalance"] 
            / len(trials)
        )

        dict_resume[file_name]["avg_time"] = round(avg_time, 3)
        dict_resume[file_name]["avg_diameter"] = round(avg_diameter, 3)
        dict_resume[file_name]["avg_imbalance"] = round(avg_imbalance, 3)




    csv_columns = [
        "name",
        "number_connex",
        "number_bal",
        "avg_time" ,
        "avg_diameter",
        "avg_imbalance"
    ]
    
    print(dict_resume)

    with open(output_local + output_file, "w") as out:
        writer = csv.DictWriter(out, fieldnames=csv_columns)
        writer.writeheader()
        for file_name in dict_resume.keys():
            writer.writerow(dict_resume[file_name])



