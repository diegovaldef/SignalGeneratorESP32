import os

def extract_code_to_txt(project_dir):
    # Directorios de origen y destino
    include_dir = os.path.join(project_dir, "include")
    src_dir = os.path.join(project_dir, "src")
    textcode_dir = os.path.join(project_dir, "textcode")
    
    # Verifica carpetas necesarias
    if not (os.path.exists(include_dir) or os.path.exists(src_dir)):
        print("Error: No se encontraron las carpetas 'include' o 'src' en el directorio del proyecto.")
        return False
    
    # Crea carpeta textcode si no existe
    os.makedirs(textcode_dir, exist_ok=True)
    
    # Contadores para estadísticas
    success_count = 0
    error_count = 0
    
    # Procesa las carpetas
    for source_dir in [d for d in [include_dir, src_dir] if os.path.exists(d)]:
        dir_name = os.path.basename(source_dir)
        target_dir = os.path.join(textcode_dir, dir_name)
        
        os.makedirs(target_dir, exist_ok=True)
        
        for root, _, files in os.walk(source_dir):
            # Crea estructura de directorios equivalente
            rel_path = os.path.relpath(root, source_dir)
            current_target_dir = os.path.join(target_dir, rel_path)
            os.makedirs(current_target_dir, exist_ok=True)
            
            for file in files:
                source_file = os.path.join(root, file)
                dest_file = os.path.join(current_target_dir, f"{file}.txt")  # Cambio clave aquí
                
                processed = False
                for encoding in ['utf-8', 'latin-1', 'iso-8859-1']:
                    try:
                        # Lee y escribe el contenido
                        with open(source_file, 'r', encoding=encoding) as f:
                            content = f.read()
                        
                        with open(dest_file, 'w', encoding='utf-8') as f:
                            f.write(content)
                        
                        print(f"Convertido: {source_file} -> {dest_file}")
                        success_count += 1
                        processed = True
                        break
                    except UnicodeDecodeError:
                        continue
                    except Exception as e:
                        print(f"Error en {source_file}: {str(e)}")
                        error_count += 1
                        processed = True
                        break
                
                if not processed:
                    print(f"Archivo no procesado: {source_file} (formato no compatible)")
                    error_count += 1
    
    # Reporte final
    print("\nResumen de conversión:")
    print(f"• Archivos convertidos: {success_count}")
    print(f"• Archivos con errores: {error_count}")
    print(f"• Ruta resultante: {textcode_dir}")
    return True

if __name__ == "__main__":
    current_dir = os.getcwd()
    print("=== Conversor de código a TXT con extensiones originales ===")
    
    if input(f"¿Usar directorio actual ({current_dir})? [s/n]: ").lower() in ['s', 'si']:
        project_dir = current_dir
    else:
        project_dir = input("Introduce la ruta completa del proyecto: ")
    
    extract_code_to_txt(project_dir)
